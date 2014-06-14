#include <map>
#include <string>
#include <curl/curl.h>
#include "http_transmitter.hh"

using namespace std;

int main()
{
  curl_global_init( CURL_GLOBAL_ALL );
  HttpTransmitter tx( "http://www.google.com" );
  string response = tx.make_get_request( map<string, string>() );
  printf( "GET response from the server is %s\n", response.c_str() );
  response = tx.make_post_request( "loremepsum" );
  printf( "POST response from the server is %s\n", response.c_str() );
  curl_global_cleanup();
  return 0;
}