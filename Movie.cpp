#include "catch.hpp"
#include <stdexcept>
#include <iostream>
#include "DoublyLinkedList.hpp"
#include "Movie.hpp"

Movie::Movie() {
}

Movie::Movie(std::string name, unsigned short year, std::string rating, unsigned short ranking) {
	setName(name);
	setYear(year);
	setRating(rating);
	setRanking(ranking);
}

std::string Movie::getName() {
	return name;
}

std::string Movie::getRating() {
	return rating;
}

unsigned short Movie::getYear() {
	return year;
}

unsigned short Movie::getRanking() {
	return ranking;
}

Movie& Movie::setName(std::string name) {
	Movie::name = name;
	return(*this);
}
Movie& Movie::setYear(unsigned short year) {
	if (year < 1900 || year > 2100)
		throw std::invalid_argument("Invalid year error");

	Movie::year = year;
	return(*this);
}
Movie& Movie::setRating(std::string rating) {
	if (rating != "G" && rating != "PG" && rating != "PG-13" && rating != "R" && rating != "NC-17") 
		throw std::invalid_argument("Invalid Rating");

	Movie::rating = rating;
	return(*this);
}
Movie& Movie::setRanking(unsigned short ranking) {
	if (ranking < 1 || ranking > 5) 
		throw std::invalid_argument("Invalid ranking error");

	Movie::ranking = ranking;
	return(*this);
}
bool Movie::operator== (Movie& rhs) {
	if (name == rhs.name && year == rhs.year) {
		return 1;
	}
	else {
		return 0;
	}
}
bool Movie::operator< (Movie& rhs) {
	if (ranking < rhs.ranking) {
		return 1;
	}
	else {
		return 0;
	}
}
bool Movie::operator<= (Movie& rhs) {
	if (ranking <= rhs.ranking) {
		return 1;
	}
	else {
		return 0;
	}
}
bool Movie::operator> (Movie& rhs) {
	if (ranking > rhs.ranking) {
		return 1;
	}
	else {
		return 0;
	}
}
bool Movie::operator>= (Movie& rhs) {
	if (ranking >= rhs.ranking) {
		return 1;
	}
	else {
		return 0;
	}
}
