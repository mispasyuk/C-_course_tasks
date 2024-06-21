#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
struct DatabaseObject
{
    uint64_t ID;
    std:: string NAME;
};
bool compare (DatabaseObject a, DatabaseObject b)
{
    return a.ID > b.ID;
}
class SimpleDatabase
{
    private:
        std:: vector<std:: vector<std:: vector<DatabaseObject>>> table;
        int rows;
        int cols;
    public:
        SimpleDatabase()
        {
            this->rows = 1;
            this->cols = 1;
            this->table.resize(1);
            for(int i = 0; i < 1; ++i)
            {
                this->table.at(i).resize(1);
            }
        }
        SimpleDatabase(int n)
        {
            this->rows = n;
            this->cols = n;
            this->table.resize(n);
            for(int i = 0; i < n; ++i)
            {
                this->table.at(i).resize(n);
            }
        }
        SimpleDatabase(int n, int m)
        {
            this->rows = n;
            this->cols = m;
            this->table.resize(n);
            for(int i = 0; i < n; ++i)
            {
                this->table.at(i).resize(m);
            }
        }

        bool Insert(uint64_t id, std:: string name, size_t x, size_t y)
        {
            if (x < this->rows && y < this->cols)
            {
                for (int i = 0; i < this->rows; ++i)
                {
                    for (int j = 0; j < this->cols; ++j)
                    {
                        for (int k = 0; k < size(this->table.at(i).at(j)); ++k)
                        {
                            if (this->table.at(i).at(j).at(k).ID == id)                
                                return false;
                        }
                    }
                }
            DatabaseObject Element {id, name};
            table.at(x).at(y).push_back(Element);
            }
            else
            {
                std::cout<<"wrong size of database";
                return false;
            }
            return true;
        }

        bool Remove (uint64_t id)
        {
            for (int i = 0; i < this->rows; ++i)
            {
                for (int j = 0; j < this->cols; ++j)
                {
                    for (int k = 0; k < size(this->table.at(i).at(j)); ++k)
                    {
                        if (this->table.at(i).at(j).at(k).ID == id)                
                        {
                            table.at(i).at(j).at(k).ID = NULL;
                            table.at(i).at(j).at(k).NAME = "";
                            return true;
                        }
                    }
                }
            }
            return false;
        }

    std:: vector<DatabaseObject> Data() const
    {
        std:: vector<DatabaseObject> ans;
        for (int i = 0; i < this->rows; ++i)
            {
                for (int j = 0; j < this->cols; ++j)
                {
                    for (int k = 0; k < size(this->table.at(i).at(j)); ++k)
                    {
                        if (table.at(i).at(j).at(k).ID != NULL)                
                        {
                            ans.push_back(table.at(i).at(j).at(k));
                        }
                    }
                }
            }
        std:: sort(ans.begin(), ans.end(), compare);
        return ans;
    }

    std:: vector<DatabaseObject> GetDataByName (std::string name) const
    {
        std:: vector<DatabaseObject> ans;
        for (int i = 0; i < this->rows; ++i)
            {
                for (int j = 0; j < this->cols; ++j)
                {
                    for (int k = 0; k < size(this->table.at(i).at(j)); ++k)
                    {
                        if (table.at(i).at(j).at(k).NAME==name)                
                        {
                            ans.push_back(table.at(i).at(j).at(k));
                        }
                    }
                }
            }
        std:: sort(ans.begin(), ans.end(), compare);
        return ans;
    }

    std:: vector<DatabaseObject> GetDataByPosition(size_t x, size_t y) const
    {
        std:: vector<DatabaseObject> ans;
        if (x < this->rows && y < this->cols)
        {
            for (int i = 0; i < size(this->table.at(x).at(y)); ++i)
            {
                ans.push_back(table.at(x).at(y).at(i));
            } 
        }
        std:: sort(ans.begin(), ans.end(), compare);
        return ans;
    }
};

int main()
{
    SimpleDatabase DATA_BASE(2, 4);
    std:: vector<DatabaseObject> answer;

    /*
    std:: string name = "";
    uint64_t id = 0;
    size_t x = 0, y = 0;
    */

    DATA_BASE.Insert(1, "Probability_theory", 1, 2);
    DATA_BASE.Insert(2, "Calculus", 1, 1);
    DATA_BASE.Insert(3, "Algorithms_and_data_structures", 0, 1);
    DATA_BASE.Insert(6, "Linear_algebra", 1, 1);
    DATA_BASE.Insert(7, "Probability_theory", 1, 3);
    DATA_BASE.Insert(9, "Probability_theory", 1, 0);
    DATA_BASE.Insert(5, "Probability_theory", 1, 0);
    answer = DATA_BASE.Data();
    std:: cout<<"Data before removing: "<<"\n";
    for (int i = 0; i < size(answer); ++i)
    {
        std:: cout<<answer.at(i).ID<<' '<<answer.at(i).NAME<<"\n";
    }
    DATA_BASE.Remove(1);
    DATA_BASE.Remove(15);
    answer = DATA_BASE.Data();
    std:: cout<<"\n";
    std:: cout<<"Data after removing: "<<"\n";
     for (int i = 0; i < size(answer); ++i)
    {
        std:: cout<<answer.at(i).ID<<' '<<answer.at(i).NAME<<"\n";
    }
    std:: cout<<"\n";
    answer = DATA_BASE.GetDataByName("Probability_theory");
    std:: cout<<"Expected answer: "<<"\n";
    for (int i = 0; i < size(answer); ++i)
    {
        std:: cout<<answer.at(i).ID<<' '<<answer.at(i).NAME<<"\n";
    }
    std:: cout<<"\n";
    std:: cout<<"Expected answer: "<<"\n";
    answer = DATA_BASE.GetDataByPosition(1, 0);
    for (int i = 0; i < size(answer); ++i)
    {
        std:: cout<<answer.at(i).ID<<' '<<answer.at(i).NAME<<"\n";
    }
    std:: cout<<"\n";
    DATA_BASE.Insert (6, "Calculus", 0, 1);
    answer = DATA_BASE.Data();
    std:: cout<<"Data after trying to replace existing element with the same id: "<<"\n";
    for (int i = 0; i < size(answer); ++i)
    {
        std:: cout<<answer.at(i).ID<<' '<<answer.at(i).NAME<<"\n";
    }
    return 0;
}