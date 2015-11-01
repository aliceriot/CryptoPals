#Exercise 11

Here we're looking to build a CBC/ECB detection oracle. There's a couple
of parts we can tackle separately:

* A function to generate a random AES-128 key (16 random bytes)
* A function that takes data and encrypts it using a random key. This
  function should encrypt using ECB half of the time, and CBC the other
  half.
* Another function which, given the output of the above, determines
  whether the ciphertext was encrypted using ECB or CBC.

I wrote this program using CWEB, which was a lot of fun! Make knows what
to do if you just want to run the program. If you want to generate the fun
documentation you can do:

```
make docs
```

You need a bunch of stuff installed, sadly, for this to work. If you're on
debian/ubuntu something like

```
sudo apt-get install cweb-latex
```

should take care of all the deps (assuming you already have `pkg-config`,
`cmake`, and the headers for `OpenSSL` installed).
