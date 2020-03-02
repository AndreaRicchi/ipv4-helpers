#ifndef IPV4_HELPER
#define IPV4_HELPER

#pragma once

#include <algorithm>
#include <string>
#include <vector>

#include <cassert>
#include <cstdint>

class IPv4Helper {
public:
    IPv4Helper() {}
    IPv4Helper(const uint8_t data[4])
    {
        m_data[0] = data[0];
        m_data[1] = data[1];
        m_data[2] = data[2];
        m_data[3] = data[3];
    }
    IPv4Helper(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
    {
        m_data[0] = a;
        m_data[1] = b;
        m_data[2] = c;
        m_data[3] = d;
    }
    IPv4Helper(uint32_t address)
        : m_data32(address)
    {
    }

    uint8_t operator[](int i) const
    {
        assert(i >= 0 && i < 4);
        return m_data[i];
    }

    std::string toString() const
    {
        return std::to_string(m_data[0]) + "."
            + std::to_string(m_data[1]) + "."
            + std::to_string(m_data[2]) + "."
            + std::to_string(m_data[3]);
    }

    uint32_t to32bit() const {
        return m_data32;
    }
    bool isZero() const { return m_data32 == 0; }

    bool operator==(const IPv4Helper& other) const { return m_data32 == other.m_data32; }
    bool operator!=(const IPv4Helper& other) const { return m_data32 != other.m_data32; }

    static IPv4Helper fromString(const std::string& string)
    {
        auto split = [](const std::string& str, const std::string& delim) {
            std::vector<std::string> output;
            auto first = std::cbegin(str);
            while (first != std::cend(str)) {
                const auto second = std::find_first_of(first, std::cend(str),
                    std::cbegin(delim), std::cend(delim));
                if (first != second)
                    output.emplace_back(first, second);
                if (second == std::cend(str))
                    break;
                first = std::next(second);
            }
            return output;
        };

        if (string.empty())
            return {};

        auto p = split(string, ".");
        if (p.size() != 4)
            return {};

        const auto a = std::stoul(p.at(0));
        if (a > 255)
            return {};

        const auto b = std::stoul(p.at(1));
        if (b > 255)
            return {};

        const auto c = std::stoul(p.at(2));
        if (c > 255)
            return {};

        const auto d = std::stoul(p.at(3));
        if (d > 255)
            return {};

        return IPv4Helper(a, b, c, d);
    }

private:
    union {
        uint8_t m_data[4];
        uint32_t m_data32{ 0 };
    };
};

#endif // IPV4_HELPER
