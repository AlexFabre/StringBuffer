#include "../../src/strbuff.h"

new_strbuff(url, , "google.com");
new_strbuff(endpoint, , "/test");

static unsigned long build_command(const strbuff *_out, const strbuff *_url, const strbuff *_endpoint)
{
    return strbuff_printf(_out, "AT#HTTPSND=\"%s\",\"%s\"", _url->str, _endpoint->str);
}

int main(void)
{
    unsigned long n;

    new_strbuff(at_cmd, 40, 0);

    n = build_command(&at_cmd, &url, &endpoint);
    printf("1) Command size %lu > %s\n", n, at_cmd.str);

    /* Assemble mutiple strings when destinaiton buffer is too short */
    new_strbuff(at_cmd2, 20, 0);

    n = build_command(&at_cmd2, &url, &endpoint);
    printf("2) Command size %lu > %s\n", n, at_cmd2.str);

    return 0;
}
