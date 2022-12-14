# include "SimpleSocket.hpp"

ns::SimpleSocket::SimpleSocket(int &domain, int &type, int &protocol, int &port, u_long &interface)
{
    init_addr(domain, type, port, interface);
    sock_fd = socket(domain, type, protocol);
    test_connection(sock_fd);
}

ns::SimpleSocket::~SimpleSocket()
{
}

void    ns::SimpleSocket::init_addr(int &domain, int &type, int &port, u_long &interface)
{
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface); // my IP address
}

void    ns::SimpleSocket::test_connection(int &sock_fd) const //consider this later as the server should not stop at any case
{
    std::cout << sock_fd << std::endl;
    if (sock_fd < 0)
    {
        std::cout << "Error\n";
    }
    //else //consider this case
}

const struct sockaddr_in &ns::SimpleSocket::get_address() const
{
    return address;
}

const int &ns::SimpleSocket::get_socket_fd() const
{
    return sock_fd;
}
