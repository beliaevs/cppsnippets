#pragma once

#include <ostream>
#include <iomanip>
#include <string>
#include <vector>

class Table
{
public:
  Table(std::vector<std::string> header) : d_header(std::move(header))
  {
  }

  void addRow(std::string name, std::vector<int> row)
  {
    d_maxNameWidth = std::max(d_maxNameWidth, (int)name.size());
    d_rows.push_back(std::move(row));
    d_rowNames.push_back(std::move(name));
  }

  void print(std::ostream& os) const
  {
    printHeader(os);
    for (int i = 0; i != (int)d_rows.size(); ++i)
      printRow(os, i);
  }

private:
  void printHeader(std::ostream& os) const
  {
    os << std::setw(d_maxNameWidth) << std::right << d_header[0];
    for(int i = 1; i != (int)d_header.size(); ++i)
    {
      const auto& e = d_header[i];
      os << std::setw(e.size() + 1) << std::right << e;
    }
    os << "\n";
  }

  void printRow(std::ostream& os, int i) const
  {
    const auto& row = d_rows[i];
    os << std::setw(d_maxNameWidth) << std::right << d_rowNames[i];
    for (int j = 0; j != (int)row.size(); ++j)
    {
      os << std::setw(int(d_header[j+1].size()) + 1) << std::right << row[j];
    }
    os << "\n";
  }

  std::vector<std::string> d_header;
  std::vector<std::vector<int>> d_rows;
  std::vector<std::string> d_rowNames;
  int d_maxNameWidth = 0;
};