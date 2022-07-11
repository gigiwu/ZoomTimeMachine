#include <iostream>
using namespace std;

class TIME
{
    public:
        int seconds;
        int minutes;
        int hours;
        TIME(): seconds(0), minutes(0), hours(0){}
        TIME(string s){
            this->hours=stoi(s.substr(0,2));
            this->minutes=stoi(s.substr(3,2));
            this->seconds=stoi(s.substr(6,2));
        }
};

void computeTimeDifference( TIME big,  TIME small,  TIME *difference){
    
    if(small.seconds > big.seconds)
    {
        --big.minutes;
        big.seconds += 60;
    }

    difference->seconds = big.seconds - small.seconds;
    if(small.minutes > big.minutes || big.minutes <0)
    {
        --big.hours;
        big.minutes += 60;
    }
    difference->minutes = big.minutes-small.minutes;
    difference->hours = big.hours-small.hours;
}

int main() {
    string s;
    cin >> s;
    TIME start = TIME(s);

    while(getline(cin,s)){
        if(s.length()<2) continue;
        if(s.length()>3 && s[2]!=':'){
            cout << s << endl;
            continue;
        }
        TIME t =  TIME(s.substr(0,8));
        string r = s.substr(9, s.length()-9);
        TIME d;
        computeTimeDifference(t, start, &d);
        cout << d.hours << ":" << d.minutes << ":" << d.seconds << " " << r << endl;
    }
    return 0;
}