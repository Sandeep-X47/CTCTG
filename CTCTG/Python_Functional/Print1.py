import json

# Load JSON data
with open("D:\\STARTED\\CTCTG\\Data\\Routes.json", "r") as f:
    data = json.load(f)

cities = [city.lower() for city in data.get("cities", [])]
routes = data.get("routes", [])

# --- Get input from user ---
start = input("From: ").strip().lower()
dest = input("To: ").strip().lower()
via_input = input("Via (enter 'direct' if no intermediate city): ").strip().lower()

# Convert via input to list
via_list = [] if via_input == "direct" else [city.strip().lower() for city in via_input.split(",")]

# Validate cities
if start not in cities:
    print(f"Error: Starting city '{start}' is not in the list of available cities.")
    exit()
if dest not in cities:
    print(f"Error: Destination city '{dest}' is not in the list of available cities.")
    exit()
for city in via_list:
    if city not in cities:
        print(f"Error: Via city '{city}' is not in the list of available cities.")
        exit()

# Find matching route
def match_route(route):
    return (
        route["from"].lower() == start and
        route["to"].lower() == dest and
        [v.lower() for v in route.get("via", [])] == via_list
    )

matched_route = next((r for r in routes if match_route(r)), None)

# Display output
if matched_route:
    via_display = matched_route.get("via", [])
    print(f"\nRoute from {matched_route['from']} to {matched_route['to']} via {via_display}:\n")
    for mode, details in matched_route.get("modes", {}).items():
        print(f"  {mode.capitalize()}: {details['distance_km']} km, {details['time_hr']} hr, ₹{details['cost_inr']}")
else:
    print(f"\nNo matching route found from '{start}' to '{dest}' via '{via_input}'.")
