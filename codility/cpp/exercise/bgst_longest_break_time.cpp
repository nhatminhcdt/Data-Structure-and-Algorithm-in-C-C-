/**
 * @brief Find the longest period of break time 
 * 
 * Use C++ to create a function "int solution(string &S)" to find the longest period of break time for a busy man,
 * with S is M lines input string of meeting schedule (start-end) in the format "Ddd hh:mm-hh:mm" where:
 *  Ddd: day of week.
 *  hh: hour
 * 	mm: minute
 * Example:
 *  "Mon 01:00-23:00"
 *  "Tue 14:00-16:35"
 * @note The break time can begin and end on different days and should begin and end in the same week.
 * 
 */

#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define DAY_CHAR_LEN    3
#define TIME_CHAR_LEN   5
#define WEEK_DAYS       7
#define DAY_HOURS       24
#define DAY_MINS        DAY_HOURS * 60


struct Schedule {
    string day_of_week;
    int start_time;
    int end_time;
};


const std::map<std::string, int> DayOfWeekOrder = {
    {"Mon", 0},
    {"Tue", 1},
    {"Wed", 2},
    {"Thu", 3},
    {"Fri", 4},
    {"Sat", 5},
    {"Sun", 6},
};


int mins_convert(const string& time) {
    int hh, mm;
    sscanf(time.c_str(), "%d:%d", &hh, &mm);

    return hh * 60 + mm;
}


Schedule parse_time(string line) {
    char day[DAY_CHAR_LEN + 1];
    char start[TIME_CHAR_LEN + 1];
    char end[TIME_CHAR_LEN + 1];

    sscanf(line.c_str(), "%3s %5s-%5s", day, start, end);
    Schedule schedule;
    schedule.day_of_week = day;
    schedule.start_time = mins_convert(start);
    schedule.end_time = mins_convert(end);

    return schedule;
}


// Compare schedules for sorting
bool compare_schedule(const Schedule& a, const Schedule& b) {
    // Compare based on day_of_week using the predefined order
    if (DayOfWeekOrder.at(a.day_of_week) < DayOfWeekOrder.at(b.day_of_week))      return true;
    else if (DayOfWeekOrder.at(a.day_of_week) > DayOfWeekOrder.at(b.day_of_week)) return false;
    
    // If day_of_week is the same, compare based on start_time
    return a.start_time < b.start_time;
}


// Get days gap
int get_days_gap(const Schedule& schedule_before, const Schedule& schedule_now) {
    return DayOfWeekOrder.at(schedule_now.day_of_week) - DayOfWeekOrder.at(schedule_before.day_of_week);
}


int break_time_calc(const Schedule& schedule_before, const Schedule& schedule_now) {
    int break_time = schedule_now.start_time - schedule_before.end_time;
    break_time += get_days_gap(schedule_before, schedule_now) * DAY_MINS;

    return break_time;
}


int find_longest_break(const vector<Schedule> schedules) {
    // == Calculate boundaries ==
    // First start time (to 00:00 of Mon)
    int longest_break = schedules[0].start_time;
    longest_break += DayOfWeekOrder.at(schedules[0].day_of_week) * DAY_MINS;
    
    // Check for the gap until the end of the Sunday (Sun 24:00)
    int last_end_time = mins_convert("24:00");
    last_end_time -= schedules.back().end_time;
    last_end_time += (DayOfWeekOrder.size() - 1 - DayOfWeekOrder.at(schedules.back().day_of_week)) * DAY_MINS;
    longest_break = std::max(longest_break, last_end_time);
    cout << "longest_break: " << longest_break << std::endl;
    
    int break_time = 0;
    if (schedules.size() > 1) {
        for (unsigned int i = 1; i < schedules.size(); ++i) {
            break_time = break_time_calc(schedules[i - 1], schedules[i]);
            if (break_time > longest_break) longest_break = break_time;
        }
    }
    
    return longest_break;
}


int solution(string &S) {
    // Implement your solution here
    
    vector<Schedule> schedules;
    istringstream string_stream (S);
    
    // Parse time
    string line;
    while (getline(string_stream, line)) {
        Schedule schedule = parse_time(line);
        schedules.push_back(schedule);
    }
    // Return time of whole week in case there is no schedule
    if (schedules.begin() == schedules.end()) return WEEK_DAYS * DAY_MINS;
	
	// Sort schedules
    std::sort(schedules.begin(), schedules.end(), compare_schedule);

    return find_longest_break(schedules);
}

int main() {
    // Example usage
    // Test Case 1
    string schedule1 = "Mon 08:00-09:30\nTue 10:15-11:45\nWed 14:00-15:30\nThu 16:30-18:00\nFri 09:00-10:30\nSat 13:45-15:15";
    int result1 = solution(schedule1);
    cout << "Test Case 1: Longest break time: " << result1 << " minutes" << endl << endl;
    
    // Test Case 2
    string schedule2 = "Mon 01:00-23:00\nTue 01:00-23:00\nWed 01:00-23:00\nThu 01:00-23:00\nFri 01:00-23:00\nSat 01:00-23:00\nSun 01:00-21:00";
    int result2 = solution(schedule2);
    cout << "Test Case 2: Longest break time: " << result2 << " minutes" << endl << endl;

    // Test Case 3
    string schedule3 = "Sun 10:00-20:00\nFri 05:00-10:00\nFri 16:30-23:50\nSat 10:00-24:00\nSun 01:00-04:00\nSat 02:00-06:00\nTue 03:30-18:15\nTue 19:00-20:00\nWed 04:25-15:14\nWed 15:14-22:40\nThu 00:00-23:59\nMon 05:00-13:00\nMon 15:00-21:00";
    int result3 = solution(schedule3);
    cout << "Test Case 3: Longest break time: " << result3 << " minutes" << endl << endl;

    // Test Case with longest break from Sunday to Monday
    string schedule4 = "Sat 10:00-22:00\nSun 01:00-23:30\nMon 00:40-23:30\nTue 00:15-23:45\nWed 00:30-23:50\nThu 00:30-18:00";
    int result = solution(schedule4);
    cout << "Test Case 4: Longest break time: " << result << " minutes" << endl << endl;

    // Test Case 5
    string schedule5 = "";
    int result5 = solution(schedule5);
    cout << "Test Case 5: Longest break time: " << result5 << " minutes" << endl << endl;
    
    // Test Case 6
    string schedule6 = "Mon 01:00-23:00\nTue 10:15-11:45\nWed 14:00-15:30\nThu 16:30-18:00\nFri 09:00-10:30\nSat 13:45-15:15";
    int result6 = solution(schedule6);
    cout << "Test Case 6: Longest break time: " << result6 << " minutes" << endl << endl;
    
    // Test Case 7
    string schedule7 = "Tue 10:15-11:45\nWed 00:00-12:00\n";
    int result7 = solution(schedule7);
    cout << "Test Case 7: Longest break time: " << result7 << " minutes" << endl << endl;
    

	// hold on the screen
	getchar();
		
    return 0;
}