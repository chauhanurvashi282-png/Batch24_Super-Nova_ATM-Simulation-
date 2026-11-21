                                        # ATM Simulation in C


Problem statement: Implement a basic ATM simulation that provides essential banking operations for a single demonstration account.


A simple ATM simulation program written in C. It lets a user create an account, verify their PIN, check balance, deposit/withdraw money, and saves the data in a text file.

       Features
- Saves user details (Name, Account Number, PIN, Balance) in `data.txt`
- 4-digit PIN verification (blocks after 3 wrong tries)
- Check Balance
- Deposit Money
- Withdraw Money
- View Account Details
  

  Team Members
- **Prateek** - Main menu loop and saving data (`main`, `showmenu`, `savedata`)
- **Urvashi** - User setup and PIN check (`userdata`, `verifyPin`)
- **Chavi** - Transactions and account display (`checkbalance`, `deposit`, `withdraw`, `viewdetails`)