# Display the lines 
# that contain the string 'not installed' 
# in /var/log/bootstrap.log page-wise.
grep 'not installed' /var/log/bootstrap.log | more


# https://cf-courses-data.s3.us.cloud-object-storage.appdomain.cloud/IBM-DB0250EN-SkillsNetwork/labs/Bash%20Scripting/top-sites.txt
# contains most popular websites. 
# Find out all the websites that have the word org in them.
curl {link} | grep 'org'


# i/o
read NAME # prompts user for input and stores value in NAME
tr "[a-z]" "[A-Z]" < file.txt # capitalizes file.txt
uname -a >> newouput.txt # append data


# pipes
ls | wc -l


# Create a variable called 'color' 
# and store the string 'light green' in it.
COLOR="light green"


# Display the list of all the files whose name starts with 'b'
# and ends with '.log' in the directory /var/log.
ls /var/log/b*.log


# Display the count of all files whose name starts with 'c'
# in the /bin directory.
ls /bin/c* | wc -l


# Display the value of variable 'color'.
echo $COLOR
# Store the value of the variable 'color' 
# in a file 'color.txt'
echo $COLOR > color.txt


# prints the latest 5 warnings 
# from the /var/log/bootstrap.log file.
cat /var/log/bootstrap.log | grep warning | tail -n 5
