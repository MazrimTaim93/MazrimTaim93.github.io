using System;

namespace Lab06_JH_v1
{
    //<summary> Subclass of Account for Certificate of Deposit accounts </summary>
    public class CDAccount : Account
    {
        protected const decimal MIN_SERVICE_FEE = 8;
        protected const decimal MIN_BALANCE = 500;
        //<summary> Constructor that checks balance is greater than minimum requirement </summary>
        public CDAccount(decimal inBalance, string inName, string inAddress, AccountType inAccType) : base(inName, inAddress, inAccType)
        {

            SetBalance(inBalance);
            serviceFee = MIN_SERVICE_FEE;
            accType = AccountType.CheckingAccount;
        }
        //<summary> sets the account balance to input parameter, as long as balance > 0. return false if balance drops below minimum </summary>
        public override bool SetBalance(decimal inBalance)
        {
            if (inBalance >= 0)
                this.balance = inBalance;
            if (inBalance <= MIN_BALANCE)
                return false;
            else return true;
        }

        //<summary> sets the service fee, as long as the fee is not lower than the base fee for the account type </summary>
        public override bool SetServiceFee(decimal inFee)
        {
            if (inFee >= MIN_SERVICE_FEE)
                this.serviceFee = inFee;
            else
                return false;
            return true;
        }
    }
}
