#include "ticket.h"
int ticket::Count = 0 ;
string getCurrentDateTime()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    ostringstream oss;
    oss << put_time(localTime, "%d/%m/%y %H:%M");
    return oss.str();
}

ticket::ticket(string id, string customer, string movie, string seat, string movietime, string room,string showtime)
{
    this->TicketId = id;
    this->CustomerName = customer;
    this->MovieName = movie;
    this->Seat = seat;
    this->Price = 55000;
    this->BuyTime = getCurrentDateTime();
    this->MovieTime = movietime;
    this->Room = room;
    this->Showtime = showtime;
    // this->NameStaff = staff;
    // this->Staff_id = s_id;
}
ticket::~ticket()
{
}
void ticket::show()
{
    
    cout << "o" << std::string(38, '=') << "o" << endl;
    std::cout << "\t  TicketId:   "  << TicketId << endl;
    std::cout << "  Movie:\t"  << MovieName << endl;
    std::cout << "  Start:\t"  << MovieTime << endl;
    std::cout << "  Price:\t"  << Price << "VND " << endl;
    std::cout << "  Customer:     "  << CustomerName << endl;
    std::cout << "  BuyTime:      "  << BuyTime  << endl;
    std::cout << "  Seat:         "  << Seat << endl;
    std::cout << "  Room:         "  << Room << endl;
    std::cout << "  ShowTime:     "  << Showtime << endl;
    
    cout << "o" << std::string(38, '=') << "o";
}


string ticket::getId()
{
    return this->TicketId;
}

string ticket::getCustomerName()
{
    return this->CustomerName;
}

string ticket::getMovieName()
{
    return this->MovieName;
}

string ticket::getSeat()
{
    return this->Seat;
}

int ticket::getPrice()
{
    return this->Price;
}

string ticket::getBuyTime()
{
    return this->BuyTime;
}

string ticket::getMovieTime()
{
    return this->MovieTime;
}
string ticket::getRoom(){
    return this->Room;
}
void ticket::setId(string id)
{
    this->TicketId = id;
}

void ticket::setCustomer(string customer)
{
    this->CustomerName = customer;
}
void ticket::setShowtime(string showtime){
    this->Showtime = showtime;
}
void ticket::setMovieName(string movie)
{
    this->MovieName = movie;
}
void ticket::setMovieTime(string time)
{
    this->MovieTime = time;
}
void ticket::setSeat(string seat)
{
    this->Seat = seat;
}
void ticket::setPrice(int price)
{
    this->Price = price;
}

void ticket::setBuyTime()
{
    this->BuyTime = getCurrentDateTime();
}
void ticket::setRoom(string room){
    this->Room = room;
}
int ticket::countLines(){
    
    ifstream file("ticket.txt");
    if (!file.is_open()) {
        return 0;
    }
    int lineCount = 0;
    string line;
    while (getline(file, line)) {
        ++lineCount;
    }
    file.close();
    return lineCount;
}
void ticket::SaveToFile()
{
    ofstream outFile("ticket.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << TicketId;
        outFile << ";" << CustomerName;
        outFile << ";" << MovieName;
        outFile << ";" << Seat;
        outFile << ";" << Price;
        outFile << ";" << BuyTime;
        outFile << ";" << MovieTime;
        outFile << ";" << Room << endl;
        outFile.close();
    }
}

bool ticket::operator==(const ticket &t)
{
    if (this->TicketId == t.TicketId)
        return true;
    else
        return false;
}

ostream &operator<<(ostream &o, const ticket &t)
{
    o << t.TicketId;
    o << ";" << t.CustomerName;
    o << ";" << t.MovieName;
    o << ";" << t.Seat;
    o << ";" << t.Price;
    o << ";" << t.BuyTime;
    o << ";" << t.MovieTime;
    // o << ";" << t.NameStaff << endl;
    return o;
}