# include "Webserv.hpp"

using namespace ns;

int main(int ac, char **av)
{
    // std::string str = "GET /hello.htm HTTP/1.1\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)\r\nHost: www.tutorialspoint.com\r\n\r\nrandombody";
    // Request r = Request(str);
    
    int domain = AF_INET;
    int type = SOCK_STREAM;
    int protocol = 0;
    int port = 80;
    u_long interface = INADDR_ANY;
    int b_log = 32;
    
    std::vector<Config> configs;
    if (ac == 2)
        start_parse(av[1], configs);
    
    std::vector<Config>::iterator conf = configs.begin(); 
    // while (conf != configs.end())
    // {
    ns::Server s = ns::Server(domain, type, protocol, port, interface, b_log);
    //     conf++;
    // }
    
    return 0;
}