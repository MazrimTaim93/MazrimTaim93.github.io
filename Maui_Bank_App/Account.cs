using System;

namespace Lab06_JH_v1
{
    //<summary> Bank account class </summary>
    public abstract class Account : IAccount
    {
        protected string name, address, accNumber;
        protected decimal balance;
        protected decimal serviceFee;
        protected AccountState accState;
        protected AccountType accType;
        protected static int nextAccNum = 1000;

        //<summary> base constructor that checks name, address, and account type for valid fields </summary>
        public Account(string inName, string inAddress, AccountType inAccType)
        {
            this.accType = inAccType;
            //generate account number
            accNumber = nextAccNum.ToString();
            nextAccNum++;
            if (accType == AccountType.SavingsAccount)
                accNumber += "S";
            else if (accType == AccountType.CheckingAccount)
                accNumber += "C";
            else if (accType == AccountType.CDAccount)
                accNumber += "CD";
            SetName(inName);
            SetAddress(inAddress);
        }

        //getters and setters
        public string GetName() { return name; }
        public bool SetName(string inName)
        {
            if (string.IsNullOrEmpty(inName))
                return false;
            else
            {
                this.name = inName;
                return true;
            }
        }
        public string GetAddress() { return address; }
        public bool SetAddress(string inAddress)
        {
            if (string.IsNullOrEmpty(inAddress))
                return false;
            else
            {
                this.address = inAddress;
                return true;
            }
        }
        public string GetAccNumber() { return accNumber; }
        public decimal GetBalance() { return balance; }
        public abstract bool SetBalance(decimal inBalance);
        public decimal GetServiceFee() { return serviceFee; }
        public abstract bool SetServiceFee(decimal inFee);

        //withdraw funds unless the withdrawal would leave balance less than 0
        public bool WithdrawFunds(decimal withdrawal)
        {

            if (balance - withdrawal < 0)
                return false;
            else
            {
                balance -= withdrawal;
                return true;
            }
        }

        //add funds to the balance
        public void PayInFunds(decimal deposit) { balance += deposit; }
        public AccountState GetAccState() { return accState; }
        public AccountType GetAccountType() { return accType; }
    }
}
