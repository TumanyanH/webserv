#include <fstream>
#include <sstream>
#include "Response.hpp"

Response::Response()
{
}

Response::Response(Request &request)
{
    // this->status_code needs to be taken from request as well
    this->version = "HTTP/1.1 ";
    this->request = request;


    fill_phrase();
    fill_status_line();
    fill_headers();
    check_static();
    
    // fill_body();
}

std::ifstream   Response::open_static(std::string file)
{
    // to be changed
    // std::ifstream fs("../www/public" + file, std::fstream::out);
    // std::string str;
    // std::ostringstream ss;

    // if (!fs.is_open())
    //     fs.close();
    // else
    // {
    //     if(fs) {
    //         ss << fs.rdbuf(); // reading data
    //         str = ss.str();
    //     }
    // }
    // std::cout << str << std::endl;
}


int Response::check_static()
{
    std::string temp, uri = this->request.get_uri();
    size_t match = 0;

    if ((match = uri.find_first_of("?", 0)) < uri.size())
    {
        uri.erase(match, uri.size() - match);
    }
    match = uri.find_last_of(".");
    temp = uri.substr(match + 1, uri.size() - match);
    if (temp == "html" || temp == "htm")
        // open_static(uri);
    return 0;
}

Response::~Response()
{
}

char    *Response::get_c_response()
{
    return this->c_response;
}

void    Response::fill_phrase()
{
    if (this->status_code == 200)
        this->phrase = "OK";
    //consider other status codes
}

// int    Response::check_static()
// {
    
// }

void    Response::fill_status_line()
{
    this->status_line += this->version + std::to_string(this->status_code) + " " + this->phrase + "\r\n";
    this->raw_response += this->status_line;
}

void    Response::fill_headers()
{

    this->raw_response += "Content-Type: text/html\nContent-Length: 56\n\n<html>\n<body>\n<h1>Hello from server</h1>\n</body>\n</html>";
    this->c_response = (char *)this->raw_response.c_str(); // consider casting into non-const again
}

void    Response::fill_static_content()
{

}