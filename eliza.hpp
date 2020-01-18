#ifndef EL_H_
#define EL_H_

#include <string> 
#include <vector>
#include <boost/regex.hpp>

using namespace std;

/* Eliza Header */

namespace bot
{
    struct exchange 
    {
        boost::regex prompt;
        vector<string> responses;

        explicit exchange(const string &answer) : prompt(answer, boost::regex::icase)
        {
            //convert answer to lower case
        }
    };

    class exchangeBuilder;

    class eliza
    {
        private:    
          
            string name;
            vector<exchange> exchanges;
            vector<pair<string, string> > translations;
        
        public:     
            eliza(const string new_name = "Eliza") 
            {
                //default name to Eliza
                name = new_name;
            }

            const string bot_name() const 
            {
                return name;
            }

            exchangeBuilder responds_to(const string &promp);
            
            void add_exchange(const exchange& ex)
            {
                exchanges.push_back(ex);
            }
            
            void add_translation();
            
            string respond(const string &input) const;
        
            string translate(const string &input) const;
    };

    class exchangeBuilder
    {
        private:      
            friend eliza;
            eliza& el;

            exchange exchange_;
           
            exchangeBuilder(eliza& bot, const string &prompt) : el(bot), exchange_(prompt)
            {
            }

        public:         
            ~exchangeBuilder()
            {
                el.add_exchange(exchange_);
            }

            exchangeBuilder& with (const string &response)
            {
                exchange_.responses.push_back(response);
                return *this;
            }
    };
};

#endif 