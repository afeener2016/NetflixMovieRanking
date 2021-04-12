//
//  Movie.hpp
//  Netflix_1
//
//

#ifndef Movie_hpp
#define Movie_hpp

#include <stdio.h>
#include <string>

class Movie {
public:
    Movie();
    Movie(std::string name, unsigned short year, std::string rating, unsigned short ranking); 
    std::string getName();
    std::string getRating();
    unsigned short getYear();
    unsigned short getRanking();
    Movie& setName(std::string name);
    Movie& setYear(unsigned short year);
    Movie& setRating(std::string rating);
    Movie& setRanking(unsigned short ranking);
    bool operator== (Movie& rhs);
    bool operator< (Movie& rhs);
    bool operator<= (Movie& rhs);
    bool operator> (Movie& rhs);
    bool operator>= (Movie& rhs);
    
private:
    std::string name;
    unsigned short year;
    std::string rating;
    unsigned short ranking;
};

#endif /* Movie_hpp */
