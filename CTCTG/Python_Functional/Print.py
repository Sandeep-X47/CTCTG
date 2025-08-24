# D:\STARTED\CTCTG\Python_Functional\Print.py
import json
from pathlib import Path
import sys

print("\n================================================\n")

# --- Locate Routes.json relative to project ---
SCRIPT_DIR = Path(__file__).resolve().parent
DATA_FILE = SCRIPT_DIR.parent / "Data" / "Routes.json"

if not DATA_FILE.exists():
    print(f"ERROR: Routes.json not found at: {DATA_FILE}")
    sys.exit(1)

# Load data
with DATA_FILE.open("r", encoding="utf-8") as f:
    data = json.load(f)

cities = set(data.get("cities", []))
routes = data.get("routes", [])

# ---- User Input ----
start_city = input("From: ").strip().title()
end_city = input("To: ").strip().title()

if start_city not in cities or end_city not in cities:
    print("Invalid cities. Please choose from:", sorted(cities))
    sys.exit(0)

# ---- Filter routes directly from JSON ----
matched_routes = [
    r for r in routes if r.get("from") == start_city and r.get("to") == end_city
]

# ---- Print Results ----
if not matched_routes:
    print(f"No routes found from {start_city} to {end_city}")
else:
    print(f"\nRoutes from {start_city} to {end_city}:\n")
    for r in matched_routes:
        via = r.get("via", [])
        via_display = "[" + ", ".join(via) + "]" if via else "[]"
        print(f"from: {r['from']}, to: {r['to']}, via: {via_display}")

    print(f"\nTotal routes found: {len(matched_routes)}")

print("\n================================================\n")
