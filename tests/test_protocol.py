import unittest

def parse_packet(line):
    result = {}
    for item in line.strip().split(";"):
        key, value = item.split("=", 1)
        result[key] = value
    return result

class ProtocolTests(unittest.TestCase):
    def test_valid_packet(self):
        packet = parse_packet("TEMP=42.5;RPM=1200;STATE=OK")
        self.assertEqual(packet["TEMP"], "42.5")
        self.assertEqual(packet["RPM"], "1200")
        self.assertEqual(packet["STATE"], "OK")

    def test_malformed_packet(self):
        with self.assertRaises(ValueError):
            parse_packet("TEMP=bad")

if __name__ == "__main__":
    unittest.main()
