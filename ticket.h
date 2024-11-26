#pragma once
#include "movie.h"
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <algorithm>
class ticket
{
private:
    string TicketId;     // id
    string CustomerName; // tênh khách hangf
    string MovieName;    // tên phim
    string Seat;         // ghế ngồi
    int Price;           // giá
    string BuyTime;      // thời gian mua
    string MovieTime;    // thời gian chiếu
    string Room;         // phòng chiếu
    string Showtime;     // suat chieu

public:
    static int Count;
    string getId();
    string getCustomerName();
    string getMovieName();
    string getMovieTime();
    string getSeat();
    int getPrice();
    string getBuyTime();
    string getRoom();
    // string getNameStaff();
    // string getStaff_id();

    void setId(string);
    void setCustomer(string);
    void setMovieName(string);
    void setMovieTime(string);
    void setSeat(string);
    void setPrice(int);
    void setBuyTime();
    void setRoom(string);
    void setShowtime(string);
    // void setNameStaff(string);
    // void setStaff_id(string);

    ~ticket();
    ticket(string = "", string = "", string = "", string = "", string = "",string= "", string = "");
    void show();
    int countLines();
    void SaveToFile();
    friend ostream &operator<<(ostream &, const ticket &);
    friend istream &operator>>(istream &, ticket &);
    bool operator==(const ticket &);
};
