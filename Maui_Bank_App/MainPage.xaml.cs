namespace Lab06_JH_v1
{
    public partial class MainPage : ContentPage
    {
        Search customers = new Search();
        public MainPage()
        {
            InitializeComponent();
        }

        //clear every entry of input
        private void ClearEntries()
        {
            nameEntry.Text = string.Empty;
            addressEntry.Text = string.Empty;
            balanceEntry.Text = string.Empty;
            accTypeEntry.Text = string.Empty;
        }

        //<summary> read each entry's input and create an account of
        //specified type to add to customers </summary>
        private void OnCounterClicked(object sender, EventArgs e)
        {
            //add an account to Search's Dictionary
            string name = nameEntry.Text;
            string address = addressEntry.Text;
            string balanceStr = balanceEntry.Text;
            string accTypeStr = accTypeEntry.Text;

            //make sure every field is filled out
            if (name == null || address == null || balanceStr == null || accTypeStr == null)
            {
                feedbackLabel.Text = "Fields cannot be null.";
                return;
            }

            //make sure balance is numeric
            decimal balance;
            if (!decimal.TryParse(balanceStr, out balance))
            {
                feedbackLabel.Text = "Balance Field must be numeric.";
                return;
            }

            //make sure accountType is numeric
            int typeNum;
            AccountType type;
            if(Int32.TryParse(accTypeStr, out typeNum))
                type = (AccountType)typeNum;
            else
            {
                feedbackLabel.Text = "Accout Type Field must be numeric.";
                return;
            }
            //make sure accountType is a valid number
            if (typeNum != 0 && typeNum != 1 && typeNum != 2)
            {
                feedbackLabel.Text = "Account Type Field must be either 0, 1, or 2.";
                return;
            }

            //All fields are vetted, now we make an account
            Account acc;
            if (type == AccountType.CheckingAccount)
            {
                acc = new CheckingAccount(balance, name, address, type);
                if (customers.StoreAccount(acc))
                {
                    feedbackLabel.Text = "Checking Account " + acc.GetAccNumber() + " created.";
                    ClearEntries();
                }
            }
            else if (type == AccountType.SavingsAccount)
            {
                acc = new SavingsAccount(balance, name, address, type);
                if (customers.StoreAccount(acc))
                {
                    feedbackLabel.Text = "Checking Account " + acc.GetAccNumber() + " created.";
                    ClearEntries();
                }
            }
            else if (type == AccountType.CDAccount)
            {
                acc = new CDAccount(balance, name, address, type);
                if (customers.StoreAccount(acc))
                {
                    feedbackLabel.Text = "Checking Account " + acc.GetAccNumber() + " created.";
                    ClearEntries();
                }
            }
            else
                feedbackLabel.Text = "Account creation failed.";
        }

        //<summary>open new window when button is clicked</summary>
        public void GoToSearch(object sender, EventArgs e)
        {
            var searchWindow = new Window
            {
                Page = new SearchPage(customers)
                { }
            };

            Application.Current.OpenWindow(searchWindow);
        }
    }
}