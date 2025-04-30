#!/bin/bash

LOG_FILE="/var/log/auth.log"
OUTPUT_FILE="login_attempts.txt"

if [[ ! -f "$LOG_FILE" ]]; then
    echo "Log file $LOG_FILE does not exist."
    exit 1
fi

grep "sshd" "$LOG_FILE" | grep -E "Failed|Accepted" | while read line; do
    USERNAME=$(echo "$line" | awk '{print $9}')
    ERROR_MSG=$(echo "$line" | sed -n 's/.*(.*): \(.*\)$/\1/p')

    echo "Username: $USERNAME, Error Message: $ERROR_MSG" >> "$OUTPUT_FILE"
done

echo "Login attempts have been written to $OUTPUT_FILE."


