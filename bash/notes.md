# Filters

Filters are commands which take input and produce some output:
`wc, cat, more, head, sort`


# Pipes

Pipes commands allows us to chain filter commands like so: 
```bash
ls | sort -r
```
>The output of `ls` is used as the input for `sort`


# Shell Variables

```bash
VAR=value
```
>Scope is limited to shell

```bash
set 
```
>Shows all shell variables


# Environment Variables

Like shell variables but they have an **extended scope**. They persist in child processes spawned by the sehll in which they originate. They are set like so:

```bash
export XDG_CONFIG_HOME="$HOME/.config"
```
>Sets environment variable


```bash
env
```
>List all environment variables

```bash
unset XDG_CONFIG_HOME
```
>Unsets environment variable

# Metacharacters

```bash
# This is a comment
echo "Hello"; whoami # semicolon is a command separator  

ls /bin/ba* # lists all files in /bin that start with "ba"

ls /bin/?ash # ? is a glob match for one character

echo "\$1 each" # escapes dollar character

echo "$1 each" # quotes interpret literally but evaluate metacharacters

echo '$1 each' # interprets all characters literally
```

# I/O redirection

```bash
echo "Hello" > file.txt # redirects output
echo "Hello" >> file.txt # append output
garbage --this-option-doesnt-exist 2> err.txt # redirect stderr 
garbage --this-option-doesnt-exist 2>> err.txt # append stderr
xclip -sel c < file.txt # redirect file contents to stdinput 
```


# Command substitution

```bash
HERE=$(pwd) # replace command with output
THERE=`pwd` # !!
```


# Batch vs. Concurrent Modes

## Batch Mode

Commands run sequentially
```bash
command1; command2
```

## Concurrent Mode

Commands run in parallel
```bash
command1 & command2
```


# Scheduling Jobs Using Cron

**Cron** is a service that runs jobs at certain times.
**Crond** interprets crontab files and sends them to cron.
A **crontab** is a table of jobs and schedule data

```bash
crontab -e # opens editor
crontab -l # lists all cronjobs
crontab -r # removes all your cronjobs, opt arg for specific job
```

Syntax for crontab
```crontab
m h dom mon dow cmd
minute hour dayofmonth month dayofweek command
```

## Example

```crontab
30 15 * * 0 date >> sundays.txt
```
>Runs at 15:30 every sunday
