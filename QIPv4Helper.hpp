#ifndef QIPV4_HELPER
#define QIPV4_HELPER

#pragma once

#include <QString>
#include <QStringList>

#include <cassert>
#include <cstdint>

class QIPv4Helper {
public:
    QIPv4Helper() {}
    QIPv4Helper(const uint8_t data[4])
    {
        m_data[0] = data[0];
        m_data[1] = data[1];
        m_data[2] = data[2];
        m_data[3] = data[3];
    }
    QIPv4Helper(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
    {
        m_data[0] = a;
        m_data[1] = b;
        m_data[2] = c;
        m_data[3] = d;
    }
    QIPv4Helper(uint32_t address)
        : m_data32(address)
    {
    }

    uint8_t operator[](int i) const
    {
        assert(i >= 0 && i < 4);
        return m_data[i];
    }

    QString toString() const
    {
        return QString("%1.%2.%3.%4")
            .arg(QString::number(m_data[0]))
            .arg(QString::number(m_data[1]))
            .arg(QString::number(m_data[2]))
            .arg(QString::number(m_data[3]));
    }

    uint32_t to32bit() const {
        return m_data32;
    }
    bool isZero() const { return m_data32 == 0; }

    bool operator==(const QIPv4Helper& other) const { return m_data32 == other.m_data32; }
    bool operator!=(const QIPv4Helper& other) const { return m_data32 != other.m_data32; }

    static QIPv4Helper fromString(const QString& string)
    {
        if (string.isNull() || string.isEmpty())
            return {};

        auto p = string.split('.');
        if (p.size() != 4)
            return {};

        bool ok;
        const auto a = p.at(0).toUInt(&ok);
        if (!ok || a > 255)
            return {};

        const auto b = p.at(1).toUInt(&ok);
        if (!ok || b > 255)
            return {};

        const auto c = p.at(2).toUInt(&ok);
        if (!ok || c > 255)
            return {};

        const auto d = p.at(3).toUInt(&ok);
        if (!ok || d > 255)
            return {};

        return QIPv4Helper(a, b, c, d);
    }

private:
    union {
        uint8_t m_data[4];
        uint32_t m_data32{ 0 };
    };
};

#endif // QIPV4_HELPER
