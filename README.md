# CTCTG – Comprehensive Travel & Transport Guide

**CTCTG** is a multi-paradigm project written in C, C++, Prolog, and Python that allows users to explore travel routes, modes of transport, travel times, distances, and costs between cities in India. It features a Command-Line Interface (CLI) and reads data from JSON files (`Routes.json` and `Time.json`) for route information.

This project demonstrates how different programming paradigms can work together in a single system to achieve modularity, efficiency, and advanced functionality. (C -Imperative/Procedural, C++ -oop, Python -Functional, Prolog-Logic)

---

## Features

1. **Available Routes**  
   Lists all possible routes from a source city to a destination city.

2. **Transport Modes, Cost, Time, Distance**  
   Shows the details of each mode of transport (Bus, Train, Flight) including distance (km), duration (hours), and cost (₹).

3. **Shortest / Longest Distance Route**  
   Determines the shortest and longest route between two cities along with the travel details.

4. **Route via Specific City**  
   Checks whether a route exists between two cities passing through a given intermediate city.

5. **Travel Times for All Modes**  
   Displays travel times in hours for all modes of transport for a given route.

6. **Exit Option**  
   Safely exit the CLI application.

---

## Use of Multiple Paradigms

The CTCTG project leverages **different programming paradigms** to efficiently handle different aspects of the system:

| Paradigm                    | Language | Role in Project                                                                                                                                                 |
| --------------------------- | -------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Imperative / Procedural** | C        | Handles the main CLI menu and user interactions, calling other modules and displaying results.                                                                  |
| **Object-Oriented**         | C++      | Reads and processes JSON data, models travel routes and travel times using classes and objects, and provides modular code for travel computations.              |
| **Logical / Declarative**   | Prolog   | Can be used for pathfinding, route verification, and logical inference (e.g., checking if a route exists via an intermediate city).                             |
| **Scripting / Functional**  | Python   | Can be used for auxiliary tasks like GUI development, plotting graphs, data analysis, or future extensions such as predictive travel time or cost optimization. |

Together, these paradigms create a **hybrid system** where:

- C provides a fast and simple CLI backbone.
- C++ efficiently manages structured data using objects and JSON parsing.
- Prolog allows complex logical queries about routes and connections.
- Python enables printing of required routes using functions 

---

## Installation & Compilation

### Requirements

- **Windows OS**
- **g++ compiler** (supports C++17)
- **PowerShell** (latest recommended)
- JSON data files: `Time.json` and `Routes.json` (stored in `Data` folder)

### Steps

1. Open PowerShell and navigate to the C source folder:

```powershell
cd D:\STARTED\CTCTG\C_Imperative
Compile the C executable:


After running the executable, you will see the menu:

========== CTCTG CLI ==========
1. Available routes between From → To
2. For the chosen route, show all modes of transport, cost, time, distance
3. Shortest / Longest distance route
4. Is there a route from A → B via C
5. Travel times of all modes of transport for a given route
6. Exit
Enter the option number to perform an action.
Provide city names when prompted. Travel times and distances are displayed in a clear, user-friendly format.

Example:

From: Chennai
To: Mumbai
Route from Chennai to Mumbai:
Bus: 12 hours
Train: 10 hours
Flight: 2 hours

Notes
City names are case-insensitive when entering input.

The program uses full file paths for JSON data on Windows systems.

The project demonstrates how different programming paradigms can interoperate in a single system for efficiency and flexibility.

License
This project is open-source. Feel free to use and modify it for educational purposes.
```

