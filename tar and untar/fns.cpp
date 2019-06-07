#include <iostream>
#include <fstream>
using namespace std;

void tar_current_folder() {
  //Open text_doc_1.txt;
  fstream text_file_1 ("text_doc_1.txt");
  if (!text_file_1.is_open()) {
    cout << "unable to open text document 1.\n";
    return;
  }
  //Open text_doc_2.txt;
  fstream text_file_2 ("text_doc_2.txt");
  if (!text_file_2.is_open()) {
    cout << "unable to open text document 2.\n";
    return;
  }
  //Open text_doc_3.txt;
  fstream text_file_3 ("text_doc_3.txt");
  if (!text_file_3.is_open()) {
    cout << "unable to open text document 3.\n";
    return;
  }
  //Initializing tar1.txt
  ofstream tar_file ("tar1.txt");

  string line;
  //Copying and inputting contents from test_doc_1.txt to tar_file.txt

  while (getline(text_file_1, line)) {
    tar_file << line << "\n";
  }

  tar_file << "END_OF_THIS_FILE\n";
  text_file_1.close();

  //Copying and inputting contents from test_doc_2.txt to tar_file.txt

  while (getline(text_file_2, line)) {
    tar_file << line << "\n";
  }

  tar_file << "END_OF_THIS_FILE\n";
  text_file_2.close();

  //Copying and inputting contents from test_doc_3.txt to tar_file.txt

  while (getline(text_file_3, line)) {
    tar_file << line << "\n";
  }

  tar_file << "END_OF_THIS_FILE\n";
  text_file_3.close();

  //Closing tar_file and return
  tar_file.close();
  return;
}




void untar_file() {
  ifstream tar_file ("tar1.txt");
  if (tar_file.is_open()) {
    string line;

    ofstream text_file_1 ("text_doc_1_untar.txt");
    while(getline(tar_file, line)) {
      if (line == "END_OF_THIS_FILE") break;
      else text_file_1 << line;
    }
    text_file_1.close();

    ofstream text_file_2 ("text_doc_2_untar.txt");
    while(getline(tar_file, line)) {
      if (line == "END_OF_THIS_FILE") break;
      else text_file_2 << line;
    }
    text_file_2.close();

    ofstream text_file_3 ("text_doc_3_untar.txt");
    while(getline(tar_file, line)) {
      if (line == "END_OF_THIS_FILE") break;
      else text_file_3 << line;
    }
    text_file_3.close();

    tar_file.close();
  } else {
    cout << "Unable to open tar file.\n";
  }
}
