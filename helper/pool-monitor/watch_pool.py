# watch_pool.py
# This script monitors a pool by fetching data from a URL and logging it to a CSV file.
# It runs indefinitely, logging the timestamp and value every 5 seconds.
# You may need to install requests if not already installed:
# (open Terminal and run)
# pip install requests

import os
import csv
import time
import requests
import re

OUT = "pool_log.csv"
URL = "http://20.244.105.138:4546/"
PAT = re.compile(r"(\d+)")
ALERT_VAL = "1000"  # example

# Determine if CSV exists
file_exists = os.path.exists(OUT)

with open(OUT, "a", newline="") as f:
    writer = csv.writer(f)
    
    if not file_exists:
        writer.writerow(["timestamp","value"])  # only write header once

    while True:
        ts = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
        try:
            r = requests.get(URL, timeout=5)
            m = PAT.search(r.text)
            val = m.group(1) if m else ""
        except Exception as e:
            val = "ERR"
        
        print(f"{ts} -> {val}")
        writer.writerow([ts, val])
        f.flush()
        
        if val == ALERT_VAL:
            print("\a")  # terminal bell
            # notify_mac("Pool Alert", f"value == {ALERT_VAL} at {ts}")
        
        time.sleep(5)
