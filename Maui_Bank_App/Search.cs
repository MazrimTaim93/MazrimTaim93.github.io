using System;

namespace Lab06_JH_v1
{
    //<summary> allows unlimited accounts to be stored and searched via accNumber </summary>
    public class Search
    {
        Dictionary<string, IAccount> database = new Dictionary<string, IAccount>();

        //<summary> store an account in the dictionary with its accNumber as a key </summary>
        public bool StoreAccount(Account inAcc)
        {
            bool outputBool = false;
            try
            {
                if (!string.IsNullOrEmpty(inAcc.GetName()))
                {
                    database.Add(inAcc.GetAccNumber(), inAcc);
                    outputBool = true;
                }
            }
            catch (ArgumentException) { Console.WriteLine("This key already exists."); }
            return outputBool;
        }

        //<summary> search for an account object using the account number </summary>
        public IAccount FindAccount(string query)
        {
            query = query.ToUpper();

            if (database.ContainsKey(query))
                return database[query];
            else
                return null;
        }
    }
}
