#include <fstream>
#include <string>
using namespace std;
int main() {
    string name;
    int id, previous, current;
    double rate;
    ifstream in("customer.txt");
    ofstream out("bill.txt");
    in >> name >> id >> previous >> current >> rate;
    int units = current - previous;
    double energyCost = units * rate;
    double gst = energyCost * 0.17;
    double total = energyCost + gst;
    out << "======== ELECTRICITY BILL ========" << endl;
    out << "Customer Name   : " << name << endl;
    out << "Customer ID     : " << id << endl;
    out << "Previous Reading: " << previous << endl;
    out << "Current Reading : " << current << endl;
    out << "Units Consumed  : " << units << endl;
    out << "Rate per Unit   : Rs. " << rate << endl;
    out << "Energy Cost     : Rs. " << energyCost << endl;
    out << "GST (17%)       : Rs. " << gst << endl;
    out << "Total Payable   : Rs. " << total << endl;
    out << "==================================" << endl;
}