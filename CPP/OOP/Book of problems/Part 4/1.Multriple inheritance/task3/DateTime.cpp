#include "DateTime.h"

DateTime::DateTime(const size_t& day = 1, const size_t& month = 1, const size_t& year = 1999, const size_t& hours = 0, const size_t& minutes = 0, const size_t& seconds = 0)
    		: Date(day, month, year), Time(hours, minutes, seconds)

{   
    std::string tmp_date_time[] = { 
                    std::to_string(get_day()), std::to_string(get_month()), std::to_string(get_year()),
                    std::to_string(get_hours()), std::to_string(get_minutes()), std::to_string(get_seconds()) 
                    };

    size_t total_len = 0;
    for (size_t i = 0; i < 6; i++) total_len += strlen(tmp_date_time[i].c_str());

    total_len += 2 + 2 + 1; /* For the two / and : and one space */

    date_time = new char[total_len];

    strcpy(date_time, tmp_date_time[0].c_str());
    strcat(date_time, "/");
    strcat(date_time, tmp_date_time[1].c_str());
    strcat(date_time, "/");
    strcat(date_time, tmp_date_time[2].c_str());
    
    strcat(date_time, " ");

    strcat(date_time, tmp_date_time[3].c_str());
    strcat(date_time, ":");
    strcat(date_time, tmp_date_time[4].c_str());
    strcat(date_time, ":");
    strcat(date_time, tmp_date_time[5].c_str());
}

DateTime::DateTime(const Date& date, const Time& time) : Date(date), Time(time)
{
    /* NOTE: should be done like the default constructor, but i will leave it like this for simplicity */
    
    sprintf(date_time, "%s/%s/%s %s:%s:%s", 
            std::to_string(date.get_day()).c_str(), std::to_string(date.get_month()).c_str(), std::to_string(date.get_year()).c_str(),
            std::to_string(time.get_hours()).c_str(), std::to_string(time.get_minutes()).c_str(), std::to_string(time.get_seconds()).c_str());
}

void DateTime::print_date_time(void) const { std::cout << date_time << std::endl; }
