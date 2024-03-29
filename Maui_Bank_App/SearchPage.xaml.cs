using System.Xml.Linq;
namespace Lab06_JH_v1;

public partial class SearchPage : ContentPage
{
	Search customers;
	public SearchPage(Search customers)
	{
		InitializeComponent();
		this.customers = customers;
	}

	public void Search(object sender, EventArgs e)
	{
		string accNumber = accountEntry.Text;
        IAccount acc;

        if (customers.FindAccount(accNumber) != null)
        {
            acc = customers.FindAccount(accNumber);
			outputLabel.Text = "\n\nAccount number:\t\t" + acc.GetAccNumber() + "\n" +
                "Account name:\t\t" + acc.GetName() + "\n" +
                "Account address:\t\t" + acc.GetAddress() + "\n" +
				"Account balance:\t\t$" + String.Format("{0:0.00}", acc.GetBalance()) + "\n";
        }
		else
            outputLabel.Text = "Account not found.";
    }
}