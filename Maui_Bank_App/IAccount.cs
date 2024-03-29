using System;

namespace Lab06_JH_v1
{
    //<summary> enum to keep track of accounts' current state </summary>
    public enum AccountState
    {
        newAcc,
        active,
        underAudit,
        frozen,
        closed
    }
    //</summary> enum to keep track of account types </summary>
    public enum AccountType
    {
        SavingsAccount,
        CheckingAccount,
        CDAccount
    }

    //<summary> interface for Account </summary>
    public interface IAccount
    {
        string GetName();
        bool SetName(string name);
        string GetAddress();
        bool SetAddress(string address);
        string GetAccNumber();
        decimal GetBalance();
        bool SetBalance(decimal balance);
        bool WithdrawFunds(decimal withdrawal);
        void PayInFunds(decimal deposit);
    }
}
