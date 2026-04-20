# Restaurant Management System in C

A console-based restaurant management system written in C for the restaurant **C'est La vie**. This project was developed as a programming fundamentals course project and supports both customer-facing operations and manager back-office functions.

## Features

### Customer Mode
- **Dine-In**: Browse the full menu and place an order by entering item IDs and quantities. Supports item removal via negative quantities. Displays an itemized receipt with the total bill on checkout.
- **Reservation**: Fill out a reservation form (name, session, party size). The system automatically assigns the correct table type based on party size and confirms or rejects the booking based on availability.

### Manager Mode (Password Protected)
- Protected by a password (`Manager1234`) with a 4-attempt lockout.
- Calculate monthly salaries for three staff categories:
  - **Chefs** – rating-based bonus system
  - **Servers** – bonus based on number of tables served per month
  - **Buspersons** – hourly wage calculation
- Supports salary lookup for a single employee or all employees at once.

## Menu

| Category   | Items                                                                                     |
|------------|-------------------------------------------------------------------------------------------|
| Starters   | Soup of the day, Dynamite Prawns, Chicken Strips, Bruschetta Italiano                    |
| Entrées    | Salt and Pepper Calamari, Garlic King Prawns, Chicken Souvlaki                           |
| Mains      | Fettuccine Carbonara, Chicken Supreme, Tarragon Chicken, Spaghetti Marinara              |
| Steaks     | T-Bone, Rib on the Bone, Scotch Fillet, New York Style, Filet Mignon                    |
| Salads     | Caesar Salad, Great Salad                                                                 |
| Sides      | Mashed Potato, Stir Fry Rice, Fries and Aioli, Gravy                                    |
| Dessert    | Banana Cream Pie, Cherry Cobbler, Carrot Cake, Molten Chocolate Cake                    |

Items are ordered using their 4-digit IDs (1001–1026).

## Table Allocation (Reservations)

| Party Size | Table Type       | Max Bookings |
|------------|------------------|--------------|
| 2–3        | 2-person table   | 11           |
| 5–6        | 5-person table   | 23           |
| 7–10       | 7-person table   | 21           |
| 11–20      | Small party hall | 3            |
| 21–40      | Party hall       | 1            |

## Salary Structure

| Role        | Base Pay   | Bonus Criteria                                                                 |
|-------------|------------|--------------------------------------------------------------------------------|
| Chef        | $1,000/mo  | +5% bonus for rating 4.3–4.59 · +10% bonus for rating 4.6–5.0               |
| Server      | $400/mo    | +10% for 65–69 tables · +15% for 70–74 tables · +20% for 75+ tables         |
| Busperson   | $5/hour    | Salary = hours worked × $5                                                    |

## Project Structure

```
├── PFPROJECT.c       # Main source file (all logic)
├── PFPROJECT.exe     # Pre-compiled Windows executable
├── Menu.txt          # Formatted menu used for dine-in display
└── Menu (1).txt      # Plain-text copy of the menu
```

## Requirements

- **OS**: Windows (uses `<conio.h>`, `<windows.h>`, and `system()` calls)
- **Compiler**: Any C compiler that supports C99 or later (e.g., GCC via MinGW, MSVC)

## Building

Compile with GCC (MinGW on Windows):

```bash
gcc PFPROJECT.c -o PFPROJECT.exe
```

Or with MSVC:

```bash
cl PFPROJECT.c
```

> **Note:** `Menu.txt` must be present in the same directory as the executable for the dine-in menu display to work.

## Running

Execute the compiled binary:

```bash
PFPROJECT.exe
```

On startup you will see a welcome screen for **C'est La vie** and be prompted to select a mode:

- Press **C** – Customer mode (Dine-In or Reservation)
- Press **M** – Manager mode (requires password)
- Press **B** – Exit the program

## Usage

### Customer – Dine-In
1. Select **C** → **D**.
2. The menu is printed on screen.
3. Enter item IDs and quantities one by one; enter `0` when done.
4. A receipt with all ordered items and the total bill is displayed.

### Customer – Reservation
1. Select **C** → **R**.
2. Enter your name, preferred session (Lunch/Dinner), and number of persons.
3. The system confirms your table number or notifies you if no tables are available.

### Manager
1. Select **M** and enter the password (`Manager1234`).
2. Choose a staff category (1 = Chefs, 2 = Servers, 3 = Buspersons).
3. Choose to view a single employee (**S**) or all employees (**A**).
4. Enter the required performance data (rating / tables served / hours worked).
5. The system displays each employee's bonus and total salary for the month.
