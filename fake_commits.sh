#!/bin/bash

# List of fake commit dates over the last year
dates=("2023-04-10T12:00:00" "2023-05-15T14:30:00" "2023-06-20T09:45:00"
       "2023-07-05T18:20:00" "2023-08-12T11:15:00" "2023-09-25T16:10:00"
       "2023-10-30T13:50:00" "2023-11-22T07:30:00" "2023-12-15T20:40:00"
       "2024-01-05T09:10:00" "2024-02-10T14:55:00")

for date in "${dates[@]}"; do
    echo "Fake commit on $date" > fakefile.txt  # Create/update a dummy file
    git add .
    
    export GIT_COMMITTER_DATE="$date"
    export GIT_AUTHOR_DATE="$date"
    
    git commit -m "Commit on $date"
done
