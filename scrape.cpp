// download winhttpclient.h
// --------------------------------
#include <winhttp\WinHttpClient.h>
using namespace std;
typedef unsigned char byte;
#define foreach         BOOST_FOREACH
#define reverse_foreach BOOST_REVERSE_FOREACH

bool substrexvealue(const std::wstring& html,const std::string& tg1,const std::string& tg2,std::string& value, long& next) {
    long p1,p2;
    std::wstring wtmp;
    std::wstring wtg1(tg1.begin(),tg1.end());
    std::wstring wtg2(tg2.begin(),tg2.end());

    p1=html.find(wtg1,next);
    if(p1!=std::wstring::npos) {
        p2=html.find(wtg2,next);
        if(p2!=std::wstring::npos) {
            p1+=wtg1.size();
            wtmp=html.substr(p1,p2-p1-1);
            value=std::string(wtmp.begin(),wtmp.end());
            boost::trim(value);
            next=p1+1;
        }
    }
    return p1!=std::wstring::npos;
}
bool extractvalue(const std::wstring& html,const std::string& tag,std::string& value, long& next) {
    long p1,p2,p3;
    std::wstring wtmp;
    std::wstring wtag(tag.begin(),tag.end());

    p1=html.find(wtag,next);
    if(p1!=std::wstring::npos) {
        p2=html.find(L">",p1+wtag.size()-1);
        p3=html.find(L"<",p2+1);
        wtmp=html.substr(p2+1,p3-p2-1);
        value=std::string(wtmp.begin(),wtmp.end());
        boost::trim(value);
        next=p1+1;
    }
    return p1!=std::wstring::npos;
}
bool GetHTML(const std::string& url,std::wstring& header,std::wstring& hmtl) {
    std::wstring wurl = std::wstring(url.begin(),url.end());
    bool ret=false;
    try {
        WinHttpClient client(wurl.c_str());
        std::string url_protocol=url.substr(0,5);
        std::transform(url_protocol.begin(), url_protocol.end(), url_protocol.begin(), (int (*)(int))std::toupper);
        if(url_protocol=="HTTPS")    client.SetRequireValidSslCertificates(false);
        client.SetUserAgent(L"User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:19.0) Gecko/20100101 Firefox/19.0");
        if(client.SendHttpRequest()) {
            header = client.GetResponseHeader();
            hmtl = client.GetResponseContent();
            ret=true;
        }
    }catch(...) {
        header=L"Error";
        hmtl=L"";
    }
    return ret;
}
int main() {
    std::string url = "http://www.google.fr";
    std::wstring header,html;
    GetHTML(url,header,html));
}
