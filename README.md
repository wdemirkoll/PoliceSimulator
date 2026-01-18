# Police Simulator

Short Description 💬
-----------------
Console-based police simulator — a simple text-based police career simulation game implemented in C++. The player starts as a low-rank police officer and progresses through ranks by working, earning XP, and managing hunger and energy. The game demonstrates basic game logic, progression systems, and state management using simple C++ constructs.

Announcement 📢
------------
This project is written using C++17.

Features ✅
--------
- Start as a Police Officer and rank up by gaining XP 👮‍♂️  
- Rank system with multiple police ranks (Officer → Chief of Police) 📈  
- Work system that earns money and XP 💼  
- Salary system based on rank with multipliers 💰  
- Hunger and Energy mechanics affecting work ability 🍔⚡  
- Simple actions: Work, Eat, Rest, Exit 🎮  
- Displays player statistics: Name, Rank, Salary, Money, XP, Hunger, Energy, Total Work 📊  

Example usage / sample session 💡
------------------------------
Below is an example interaction with the program (user input shown after prompts):

```text
Enter your name: John

----------------------------------------
Name: John
Rank: Police Officer
Fixed Salary: $500
Money: $0
Total Work: 0
----------------------------------------
Hunger: 100
Energy: 100
----------------------------------------
XP: 5
Salary Multiplier: 1x
XP Multiplier: 1x
----------------------------------------

[1] - Work
[2] - Eat
[3] - Rest
[4] - Exit Game
Choose: 1
You Worked!

----------------------------------------
Name: John
Rank: Police Officer
Fixed Salary: $500
Money: $500
Total Work: 1
----------------------------------------
Hunger: 90
Energy: 90
----------------------------------------
XP: 105
Salary Multiplier: 1x
XP Multiplier: 1x
----------------------------------------

[1] - Work
[2] - Eat
[3] - Rest
[4] - Exit Game
Choose: 2
You ate a meal for $50!

[1] - Work
[2] - Eat
[3] - Rest
[4] - Exit Game
Choose: 4
```

Notes and limitations ⚠️
---------------------
- The current implementation uses global variables and simple control flow.  
- Input validation is minimal; non-numeric input may cause unexpected behavior.  
- Hunger and Energy must be managed to continue working.  
- The game is single-player and does not save progress between sessions.  

Author 👤
------
wdemirkoll — GitHub: @wdemirkoll

📅 January 2026
