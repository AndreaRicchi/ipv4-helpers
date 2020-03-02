#include <IPv4Helper.hpp>
#include <QIPv4Helper.hpp>

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    {
        auto ip = IPv4Helper();
        ip = IPv4Helper::fromString("192.168.0.1");
        printf("IPv4Helper test (1):\n");
        printf("   IP: %s\n", ip.toString().c_str());
        printf("   IP: %u.%u.%u.%u\n", ip[0], ip[1], ip[2], ip[3]);
        printf("   IP as 32bit: %u\n", ip.to32bit());
        printf("   IP %s zero\n", ip.isZero() ? "is" : "is not");
        ip = IPv4Helper(17475776);
        printf("\nIPv4Helper test (2):\n");
        printf("   IP: %s\n", ip.toString().c_str());
        printf("   IP: %u.%u.%u.%u\n", ip[0], ip[1], ip[2], ip[3]);
        printf("   IP as 32bit: %u\n", ip.to32bit());
        printf("   IP %s zero\n", ip.isZero() ? "is" : "is not");
        ip = IPv4Helper(0, 0, 0, 0);
        printf("\nIPv4Helper test (3):\n");
        printf("   IP %s zero\n\n", ip.isZero() ? "is" : "is not");
    }

    {
        auto ip = QIPv4Helper();
        ip = QIPv4Helper::fromString("192.168.10.1");
        printf("\nQIPv4Helper test (1):\n");
        printf("   IP: %s\n", ip.toString().toStdString().c_str());
        printf("   IP: %u.%u.%u.%u\n", ip[0], ip[1], ip[2], ip[3]);
        printf("   IP as 32bit: %u\n", ip.to32bit());
        printf("   IP %s zero\n", ip.isZero() ? "is" : "is not");
        ip = QIPv4Helper(16820416);
        printf("\nQIPv4Helper test (2):\n");
        printf("   IP: %s\n", ip.toString().toStdString().c_str());
        printf("   IP: %u.%u.%u.%u\n", ip[0], ip[1], ip[2], ip[3]);
        printf("   IP as 32bit: %u\n", ip.to32bit());
        printf("   IP %s zero\n", ip.isZero() ? "is" : "is not");
        ip = QIPv4Helper(0, 0, 0, 0);
        printf("\nQIPv4Helper test (3):\n");
        printf("   IP %s zero\n\n", ip.isZero() ? "is" : "is not");
    }

    return 0;
}
