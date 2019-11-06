import pickle



class Account:
    def __init__(self, name, pin,balance = 0.0):
        self.account_dict = {"name":name, "pin":pin, "balance":float(balance)}

    def deposit(self,amount):
        self.account_dict["balance"] += amount

    def withdraw(self,amount):
        self.account_dict["balance"] -= amount

    def getBalance(self):
        return self.account_dict["balance"]

    def getPin(self):
        return self.account_dict["pin"]

    def __str__(self):
        return "Name    : {}\nPIN     : {}\nBalance : {}".format(self.account_dict["name"],self.account_dict["pin"],self.account_dict["balance"])





class Bank:
    def __init__(self):
        self.account_list = list()

    def add(self,account):
        self.account_list.append(account)

    def print(self):
        for account in self.account_list:
            print(account)


    def remove(self,PIN):
        for account in self.account_list:
            if(account.getPin() == PIN):
                self.account_list.remove(account)

    def get(self,PIN):
        for account in self.account_list:
            if(account.getPin() == PIN):
                return account

    # pickle dump
    def save(self,fileName = None):
        if fileName != None:
            self._fileName = fileName
        elif self._fileName == None:
            return
        fileobj = open(self._fileName,'wb')
        for account in self.account_list:
            pickle.dump(account.account_dict,fileobj)
        fileobj.close()

    # pickle load
    def show(self,fileName = None):
        if fileName != None:
            self._fileName = fileName
        elif self._fileName == None:
            return
        fileobj = open(self._fileName,"rb")
        data = []
        for count in range(len(self.account_list)):
            data.append(pickle.load(fileobj))

        for count in range(len(self.account_list)):
            print(data[count])

        fileobj.close()

    def ATM(self):
        print("Welcome DGU BANK!!\n")
        print("Loading Account!!!")
        print("Done!\n")
        print("------------------Account in the Bank--------------")
        self.show("temp.pickle")

        input_pin = input("Enter account pin : ")
        if input_pin == "admin":
            while(True):
                print("1 - View Machine 2 - Add Account 3 - Remove Account 4 - Exit")
                selection = int(input("Enter your selection : "))
                if selection == 1:
                    input_pin = input("Enter account pin : ")
                    account = bank.get(input_pin)
                    print(account)

                elif selection == 2:
                    name = input("Name : ")
                    pin = input("PIN : ")
                    balance = float(input("BALANCE : "))
                    bank.add(Account(name, pin, balance))
                    print("\nAdded. OK")

                elif selection == 3:
                    input_pin = input("PIN number : ")
                    yes_or_no = input("Is remove Account, Yes or No ? {}  ".format(input_pin))
                    if yes_or_no == "Yes" or yes_or_no == "yes" or yes_or_no == "YES":
                        bank.remove(input_pin)
                        print("Removed. OK")

                elif selection == 4:
                    print("\nSaving Account")
                    self.save("temp.pickle")

                    print("Done\n")
                    print("Bye!!")
                    break
        else:
            while(True):
                print("1 - View Balance 2 - Withdraw 3 - Deposit 4 - Exit")
                selection = int(input("Enter your selection : "))
                if selection == 1:
                    print(bank.get(input_pin).getBalance())
                elif selection == 2:
                    deposit_amount = float(input("Enter amount to deposit : "))
                    bank.get(input_pin).deposit(deposit_amount)
                    print("Updated Balance :",bank.get(input_pin).getBalance())
                elif selection == 3:
                    withdraw_amount = float(input("Enter amount to withdraw : "))
                    bank.get(input_pin).withdraw(withdraw_amount)
                    print("Updated Balance :", bank.get(input_pin).getBalance())
                elif selection == 4:
                    print("\n\nSaving Account")
                    self.save("temp.pickle")

                    print("Done\n")
                    print("Bye DGU Bank!")
                    break


bank = Bank()
bank.add(Account("Wilma","1001",4000.00))
bank.add(Account("Fred","1002",1000.00))
bank.print()


print()
account = bank.get("1001")
print(account)


bank.ATM()
