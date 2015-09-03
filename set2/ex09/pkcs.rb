class Pkcs7
  attr_reader :plaintext
  def initialize(plaintext, padded_length)
    @plaintext = plaintext.bytes
    @padded_length = padded_length
  end

  def pad
    diff = @padded_length - @plaintext.length
    1.upto(diff) do
      @plaintext << diff
    end
  end
end
