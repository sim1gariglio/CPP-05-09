#!/bin/bash

# Log file to store the results
LOG_FILE="$(pwd)/$(date +%Y%m%d_%H%M%S)_build_results.ans"

# Clear the log file if it exists
> "$LOG_FILE"

# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to process directories recursively
process_directory() {
    local dir="$1"
    echo -e "Processing directory: $dir" | tee -a "$LOG_FILE"
    echo -e "${BLUE}==========================${NC}" | tee -a "$LOG_FILE"
    cd "$dir"

    # Try to run `make`
    if make &> /dev/null; then
        echo -e "${GREEN}make: SUCCESS${NC}" | tee -a "$LOG_FILE"
    else
        echo -e "${RED}make: ERROR${NC}" | tee -a "$LOG_FILE"
    fi

    # Try to run `make clean`
    if make clean &> /dev/null; then
        echo -e "${GREEN}make clean: SUCCESS${NC}" | tee -a "$LOG_FILE"
    else
        echo -e "${RED}make clean: ERROR${NC}" | tee -a "$LOG_FILE"
    fi

    # Try to run `make fclean`
    if make fclean &> /dev/null; then
        echo -e "${GREEN}make fclean: SUCCESS${NC}" | tee -a "$LOG_FILE"
    else
        echo -e "${RED}make fclean: ERROR${NC}" | tee -a "$LOG_FILE"
    fi

    cd - &> /dev/null
    echo -e "${BLUE}==========================${NC}" | tee -a "$LOG_FILE"
    echo "" | tee -a "$LOG_FILE"
}

# Find all directories containing a Makefile and process them
find . -type f -name 'Makefile' -exec dirname {} \; | while read -r dir; do
    echo "[$(date)]" | tee -a "$LOG_FILE"
    process_directory "$dir"
    echo -e "${BLUE}==========================${NC}" | tee -a "$LOG_FILE"
    echo "" | tee -a "$LOG_FILE"
done