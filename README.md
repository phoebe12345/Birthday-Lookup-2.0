# Birthday-Lookup-2.0

• Option 1: to load a birthday file – ask the user to input the name of the file containing birthday
information and load the entries from that file (report # of entries). Note that the file can be nonexistent (if so the program should print the error and keep running), but if it exists you can assume
the format inside that file is consistent (birthday, name, known-for), with each string at most 100
characters. it is possible for the user to load a different file by choosing this option again.

• Option 2: to list birthdays sorted by Month-Day – list the birthday entries from Jan 1 to Dec 31.
If a day has no entry, there is no need to print anything. If on that day there are more than one
birthday entry, any order within that day is acceptable.

• Option 3: to lookup a birthday – ask the user for a month and then a day, then report all entries
with the same birthday (regardless of the year). There can be more than one entry on any day.
  o If one or more entries are found, print all the information. Any order is acceptable.
  o If no entry is found, print “No such birthday on record.”
There is no need to check if the input date is valid (e.g., 2-31 will just result in the no-entry case).

• Option 4: to add a birthday – ask the user for all the information for a birthday (year, month, day,
name, known-for) and add it to the currently loaded entries. Print a feedback and look for
duplicates (only check for same year, month, day, and name, do not check for known-for).
  o If no duplicate is found, add this birthday and print “Birthday added.”
  o If a duplicate is found, print “An entry with the same birthday and name already exists.
Nothing added.”
There is no need to check if the input date is valid (e.g., 2-31 will still be added if no duplicate).

• Option 5: to save a birthday file – ask the user to input the name of a file to which the current
entries will be saved in the same format as the sample files. It is possible for the name to be the
same as the file just being loaded. If so, it will be overwritten. Report # entries when done.

• Option 6: to terminate the program – thank the user and end the program.
