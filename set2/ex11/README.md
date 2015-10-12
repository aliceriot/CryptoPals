#Exercise 11

Here we're looking to build a CBC/ECB detection oracle. There's a couple
of parts we can tackle separately:

* A function to generate a random AES-128 key (16 random bytes)
* A function that takes data and encrypts it using a random key. This
  function should encrypt using ECB half of the time, and CBC the other
  half.
* Another function which, given the output of the above, determines
  whether the ciphertext was encrypted using ECB or CBC.
