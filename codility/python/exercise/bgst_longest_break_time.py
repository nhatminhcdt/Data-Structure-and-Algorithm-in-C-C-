"""
  @brief Find the longest period of break time

  Create a function "int solution(string &S)" to find the longest period of break time for a busy man,
  with S is M lines input string of meeting schedule (start-end) in the format "Ddd hh:mm-hh:mm" where:
    Ddd: day of week.
    hh: hour
    mm: minute

  @example:
    "Mon 01:00-23:00"
    "Tue 14:00-16:35"

  @note The break time can begin and end on different days and should begin and end in the same week.

 """

from typing import List

DAY_CHAR_LEN  = 3
TIME_CHAR_LEN = 5
WEEK_DAYS     = 7
DAY_HOURS     = 24
DAY_MINS      = DAY_HOURS * 60


class Schedule:
  def __init__(self, day_of_week:str, start_time:int, end_time:int):
    self.day_of_week  = day_of_week
    self.start_time   = start_time
    self.end_time     = end_time


DayOfWeekOrder = {
  "Mon": 0,
  "Tue": 1,
  "Wed": 2,
  "Thu": 3,
  "Fri": 4,
  "Sat": 5,
  "Sun": 6,
}


def mins_convert(time) -> int:
  hh, mm = map(int, time.split(':'))
  return hh * 60 + mm


def parse_time(line) -> Schedule:
  day, time_ = line.split()
  start, end = time_.split('-')
  return Schedule(day, mins_convert(start), mins_convert(end))


def compare_schedule(a:Schedule, b:Schedule) -> bool:
  if DayOfWeekOrder[a.day_of_week] < DayOfWeekOrder[b.day_of_week]:
    return True
  elif DayOfWeekOrder[a.day_of_week] > DayOfWeekOrder[b.day_of_week]:
    return False
  return a.start_time < b.start_time


def get_days_gap(schedule_before:Schedule, schedule_now:Schedule) -> int:
  return DayOfWeekOrder[schedule_now.day_of_week] - DayOfWeekOrder[schedule_before.day_of_week]
   

def break_time_calc(schedule_before:Schedule, schedule_now:Schedule) -> int:
    break_time = schedule_now.start_time - schedule_before.end_time
    break_time += get_days_gap(schedule_before, schedule_now) * DAY_MINS

    return break_time


def find_longest_break(schedules:List[Schedule]) -> int:
  # == Calculate boundaries ==
  # First start time (to 00:00 of Mon)
  longest_break = schedules[0].start_time
  longest_break += DayOfWeekOrder[schedules[0].day_of_week] * DAY_MINS

  # Last end time (to 24:00 of Sun)
  last_end_time = mins_convert("24:00")
  last_end_time -= schedules[-1].end_time
  last_end_time += (WEEK_DAYS - 1 - DayOfWeekOrder[schedules[-1].day_of_week]) * DAY_MINS
  longest_break = max(longest_break, last_end_time)

  if len(schedules) > 1:
    for i in range(1, len(schedules)):
      break_time = break_time_calc(schedules[i - 1], schedules[i])
      longest_break = max(longest_break, break_time)

  return longest_break


def solution(S):
  # Return 7 days if no schedule
  if not S:
    return DAY_MINS * WEEK_DAYS
  
  # Parse input string
  schedules = [parse_time(line) for line in S.split('\n')]
  
  # Sort schedules by day of week and start time
  schedules.sort(key=lambda x: (DayOfWeekOrder[x.day_of_week], x.start_time))
  for schedule in schedules:
    print(schedule.day_of_week, schedule.start_time, schedule.end_time)

  return find_longest_break(schedules)    


# main function
if __name__ == '__main__':
  # Example usage
  # Test Case 1
  schedule1 = "Mon 08:00-09:30\nTue 10:15-11:45\nWed 14:00-15:30\nThu 16:30-18:00\nFri 09:00-10:30\nSat 13:45-15:15"
  result1 = solution(schedule1)
  print(f"Test Case 1: Longest break time: {result1} minutes\n")

  # Test Case 2
  schedule2 = "Mon 01:00-23:00\nTue 01:00-23:00\nWed 01:00-23:00\nThu 01:00-23:00\nFri 01:00-23:00\nSat 01:00-23:00\nSun 01:00-21:00"
  result2 = solution(schedule2)
  print(f"Test Case 2: Longest break time: {result2} minutes\n")

  # Test Case 3
  schedule3 = "Sun 10:00-20:00\nFri 05:00-10:00\nFri 16:30-23:50\nSat 10:00-24:00\nSun 01:00-04:00\nSat 02:00-06:00\nTue 03:30-18:15\nTue 19:00-20:00\nWed 04:25-15:14\nWed 15:14-22:40\nThu 00:00-23:59\nMon 05:00-13:00\nMon 15:00-21:00"
  result3 = solution(schedule3)
  print(f"Test Case 3: Longest break time: {result3} minutes\n")

  # Test Case with the longest break from Sunday to Monday
  schedule4 = "Sat 10:00-22:00\nSun 01:00-23:30\nMon 00:40-23:30\nTue 00:15-23:45\nWed 00:30-23:50\nThu 00:30-18:00"
  result4 = solution(schedule4)
  print(f"Test Case 4: Longest break time: {result4} minutes\n")

  # Test Case 5
  schedule5 = ""
  result5 = solution(schedule5)
  print(f"Test Case 5: Longest break time: {result5} minutes\n")

  # Test Case 6
  schedule6 = "Mon 01:00-23:00\nTue 10:15-11:45\nWed 14:00-15:30\nThu 16:30-18:00\nFri 09:00-10:30\nSat 13:45-15:15"
  result6 = solution(schedule6)
  print(f"Test Case 6: Longest break time: {result6} minutes\n")

  # Test Case 7
  schedule7 = "Tue 10:15-11:45\nWed 00:00-12:00"
  result7 = solution(schedule7)
  print(f"Test Case 7: Longest break time: {result7} minutes\n")

