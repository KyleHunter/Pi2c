import smbus
import time

class Pi2c:
	
	def __init__(self, address, bus):
		self.address = address
		self.bus = bus
		
	@staticmethod
	def _convert_to_chars(item):
		return [ord(x) for x in str(item)]
		
	@staticmethod
	def _convert_from_chars(item_array):
		return "".join([chr(i) for i in item_array])
		
	def read_response(self, cmd):
		try:
			char_array = self.bus.read_i2c_block_data(self.address, cmd)
		except IOError:
			print("Caught")
			return None
		new_array = []
		for i in char_array:
			if i is 0:
				break
			new_array.append(i)

		return self._convert_from_chars(new_array)
		
	def _write_byte(self, value):
		self.bus.write_byte(self.address, value)
		
	def _read_byte(self):
		return self.bus.read_byte(self.address)