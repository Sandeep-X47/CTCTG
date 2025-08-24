import json

# Load JSON data
with open("D:\\STARTED\\CTCTG\\Data\\Routes.json", "r") as f:
    data = json.load(f)

cities = [city.lower() for city in data.get("cities", [])]
routes = data.get("routes", [])

# --- Get input from user ---
start = input("From: ").strip().lower()
dest = input("To: ").strip().lower()

# Validate cities
if start not in cities:
    print(
        f"Error: Starting city '{start}' is not in the list of available cities.")
    exit()
if dest not in cities:
    print(
        f"Error: Destination city '{dest}' is not in the list of available cities.")
    exit()

# Find all routes from start to dest
matching_routes = [r for r in routes if r["from"].lower() ==
                   start and r["to"].lower() == dest]

if not matching_routes:
    print(f"No routes found from {start.title()} to {dest.title()}.")
    exit()

# Helper functions to find shortest and longest distance based on any mode


def route_min_distance(route):
    modes = route.get("modes", {})
    return min(details["distance_km"] for details in modes.values()) if modes else float('inf')


def route_max_distance(route):
    modes = route.get("modes", {})
    return max(details["distance_km"] for details in modes.values()) if modes else 0


# Find shortest and longest routes
shortest_route = min(matching_routes, key=route_min_distance)
longest_route = max(matching_routes, key=route_max_distance)

# Display the shortest route
via_display = shortest_route.get("via", [])
print(
    f"\nShortest route from {shortest_route['from']} to {shortest_route['to']} via {via_display}:")
for mode, details in shortest_route.get("modes", {}).items():
    print(
        f"  {mode.capitalize()}: {details['distance_km']} km, {details['time_hr']} hr, ₹{details['cost_inr']}")

# Display the longest route
via_display = longest_route.get("via", [])
print(
    f"\nLongest route from {longest_route['from']} to {longest_route['to']} via {via_display}:")
for mode, details in longest_route.get("modes", {}).items():
    print(
        f"  {mode.capitalize()}: {details['distance_km']} km, {details['time_hr']} hr, ₹{details['cost_inr']}")
