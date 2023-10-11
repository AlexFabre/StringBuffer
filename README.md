# StrBuff

A lightweight and safe string library for C.

**MISRA-C compliant** (No malloc)

This library aims to provide a **safe-at-all-cost** way to manipulate C strings at negligeable cost.

A strbuff object is nothing more than a wrapper around a declared string buffer aiming to transport both the string reference and its size into the same object.

## Getting started

The simplest way is to grab it off github. You can also download it as a zip if you prefer.

It's made of a main header file **strbuff.h**, a config header **strbuff_config.h** and plenty of source files.

Everything you need is in **src/**.

In your project, create a **StrBuff** directory alongside your other external libraries and copy the content of **src/** into it.

~~~sh
├── StrBuff
│   ├── strbuff_add.h
│   ├── strbuff_addb.c
│   ├── strbuff_addc.c
│   ├── strbuff_addf.c
│   │...
│   └── strbuff.h
~~~

## Usage

You can now safely wrap your existing strings, or create new strbuffs, and forget about buffer overflows...

~~~c

new_strbuff(url, , "google.com");
new_strbuff(endpoint, , "/test");


static unsigned long build_command(const strbuff *_out)
{
    return strbuff_printf(_out, "AT#HTTPSND=\"%s\",\"%s\"", url->str, endpoint->str);
}

~~~

You now have access to all the functions below:
* **strbuff_add(dest, src)**
* **strbuff_addf(dest, format, ...)**

* **strbuff_print(dest, src)** 
* **strbuff_printf(dest, format, ...)**

* **strbuff_prefix(dest, src)** *not yet implemented*
* **strbuff_prefixf(dest, format, ...)** *not yet implemented*

* **strbuff_starts_with(buff, src)** 
* **strbuff_ends_with(buff, src)** 

* **strbuff_find(buff, src)** 

* **strbuff_revert(buff)**

* **strbuff_capacity(buff)**
* **strbuff_len(buff)**
* **strbuff_sanitize(buff)**
* **strbuff_clear(buff)**

## Examples

Some examples are available under **example/** both for host desktop usage and embedded targets

## Test

If you plan to help with the development (or just want to verify that it can perform its self tests on your system) then you can ask it to test:

~~~sh
make test
~~~

Unit tests are performed with [Unity](https://github.com/ThrowTheSwitch/Unity) unit test framework.

