# A list of all basic unix cmds
# Very Basics

whoami
id
date
date "+%D" # pritns cur date
date "+%T" # HH:MM:SS
ls
ls /bin/b*
ls /bin/*r
uname
uname -a
ps # lists all processes and their pids
ps -e # includes processes by other users 
top 
top -n 10
echo "Very cool cmd"
echo -e "This will be printed \nin two lines"
wget https://cf-courses-data.s3.us.cloud-object-storage.appdomain.cloud/IBM-DB0250EN-SkillsNetwork/labs/Bash%20Scripting/usdoi.txt
man ls


# Directory management
pwd
mkdir scripts
cd 
cd ..
ls -la /etc
ls -lt # ls with more info by time
ls -ld /etc # lists the dirs attributes
ls -lS # sort by size in descending order
ls -lrS # by size in ascending order
rmdir  
find /etc -name '*.txt' 
df -h # list available amount of disk space 


# File management
cat usdoi.txt
more usdoi.txt # allows us to go page by page
head usdoi.txt # prints first ten lines
head -n 3 usdoi.txt # prints first three lines
tail usdoi.txt # prints last 10 lines
cp usdoi.txt usdoi-backup.txt
mv usdoi.txt usdoi-renamed.txt
touch myfile.txt
rm -i myfile.txt # asks for confirmation first
tar -cvf bin.tar /bin # creates a bin archive in /bin -c = create new; -f = filename; -v = verbose
tar -tvf bin.tar # lists files tar files verbosely
tar -xvf bin.tar # untars archive
zip config.zip /etc/*.conf # places all /etc/*.conf in a config.zip file
zip -r bin.zip /bin # -r = recursive
unzip -l config.zip # lists all files within zip file
unzip config.zip # unzips file


# Control commands
chmod +{r,w,x} usdoi.txt # grants read, write, and execute permissions
chmod -{r,w,x} usdoi.txt # revokes read, write, and execute permissions
chmod o-r usdoi.txt # revokes read privliges for people in the "other" category
chmod u-r usdoi.txt # !! but for "user" category 


# Text processing
wc usdoi.txt # gives lines, words, and characters in file
wc -l usdoi.txt # gives lines
wc -w usdoi.txt # gives words
wc -c usdoi.txt # gives characters
grep people usdoi.txt # prints all lines which contain "people"
grep -v login /etc/passwd # prints all lines which don't contain "login"
grep -n login /etc/passwd # also prints line numbers 
grep -i login /etc/passwd # case insensitve
grep -w login /etc/passwd # only whole words


# Networking
hostname
hostname -i # views ip addr
ping www.google.com # keep sending data packets to the server and prints the response it gets back.
ping -c 5 www.google.com # !! only 5 times
ifconfig # configures or displays network interface parameters for network 
ifconfig eth0 # for ethernet adapter
curl https://youtu.be/3qeTtv6I2GQ # gets html or accesses file
curl -O https://youtu.be/3qeTtv6I2GQ # gets file and saves it


# i/o
read NAME # prompts user for input and stores value in NAME
tr "[a-z]" "[A-Z]" < file.txt # capitalizes file.txt
