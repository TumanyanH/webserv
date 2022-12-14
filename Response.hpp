#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include "Request.hpp"

class Response: public HTTP
{
    private:
        std::string     raw_response;
        char    *       c_response;
        std::string     status_line;
        std::string     phrase;
        std::string     content;
        Request         request;
    public:
        Response();
        Response(Request &); // will be needed later
        virtual ~Response();

        void            fill_phrase();
        void            fill_status_line();
        void            fill_headers();
        // void            fill_body();
        char            *get_c_response();
        void            fill_static_content();
        int             check_static();
        std::ifstream   open_static(std::string file);
};

#endif