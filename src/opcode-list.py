#!/usr/bin/python3
# Used to create the empty instruction source and header files
import requests
from bs4 import BeautifulSoup

# Scrape and parse the html from this page
url = "https://pastraiser.com/cpu/i8080/i8080_opcodes.html"
html_text = requests.get(url).text
html = BeautifulSoup(html_text, "html.parser")

# Pick out the first table element
table = html.find("table")

opcodes = [] # List of cells that describe an opcode
for tr in table.find_all("tr"):
  for td in tr.find_all("td"):
    c = str(td) # Cell is the string representation of the table data
    text = c[c.find(">")+1:c.rfind("<")] # Extract cell contents
    text = text.replace(u'\xa0\xa0', u'<br/>') # Format unicode breaks
    text = text.replace(u'\xa0', '') # Remove any stray unicode
    text = text.split("<br/>") # Make an array around the breaks
    if len(text) > 1: # Keep only the cells with multiple lines
      opcodes.append(text)

# Count the maximum opcode name length
max_name_len = 0
for op in opcodes:
  op_name, *_ = op # We only care about the name
  if len(op_name) > max_name_len:
    max_name_len = len(op_name)
#print(max_name_len)

op_funcs = [] 

print("Opcode instruction_set[256] = {")
for i, op in enumerate(opcodes):
  # Unpack the array
  op_name, op_length, op_cycles, *_ = op
  # Determine the function name for this opcode
  op_func = "opcode_"+op_name
  for replacement in ("*",""),(" ","_"),(",","_"):
    op_func = op_func.replace(*replacement)
  # Build a list of all the unique function names
  if op_func not in op_funcs:
    op_funcs.append(op_func)
  
  # Handle cases where two cycle numbers are listed
  # This means the instruction can sometimes take an extra 6 cycles to run
  if "/" in op_cycles:
    _, op_cycles = op_cycles.split("/")
    
  # Calculate padding to put after the name and cycle fields to make it look pretty
  n_pad = " "*max(0,max_name_len-len(op_name))
  c_pad = "" if int(op_cycles)>9 else " "
  # Print that sucker
  print("/*{}*/ {{ \"{}\",{} .length={}, .cycles={},{} &{} }},".format(
    hex(i)[2:].upper().zfill(2),
    op_name,n_pad,
    op_length,
    op_cycles,c_pad, op_func))
print("};")

input("\n"+"#"*25+ " instructions_impl.h " +"#"*25+"\n")

# Turn the function list into header entries
op_funcs.sort()
for func in op_funcs:
  print(f"int {func}();")

input("\n"+"#"*25+ " instructions_impl.c " +"#"*25+"\n")

# Turn the function list into header entries
op_funcs.sort()
for func in op_funcs:
  print(f"""int {func}() {{
  printf(\"'{func}' not implemented.\\n");
}}
""")
