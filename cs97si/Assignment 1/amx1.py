import numpy as np
import pandas as pd

A = raw_input()
tz_data = []
for i in range(int(A)):
    li = []
    text = raw_input()
    li = text.split(",")
    tz_data.append(li)
    
tz_data = np.array(tz_data)
df_tz_data = pd.DataFrame(tz_data)

B = raw_input()

transaction_data = []
for i in range(int(B)):
    li = []
    text = raw_input()
    li = text.split(",")
    transaction_data.append(li)
    
transaction_data = np.array(transaction_data)
df_trans_data = pd.DataFrame(transaction_data)

C = raw_input()

tip_data = []
for i in range(int(C)):
    li = []
    text = raw_input()
    li = text.split(",")
    tip_data.append(li)

tip_data = np.array(tip_data)
df_tip_data = pd.DataFrame(tip_data)

df_tz_data.columns = ["Rest_id", "GMT_diff"]
df_trans_data.columns = ["Cust_id", "Rest_id", "Date", "Time", "Amount"]
df_tip_data = pd.DataFrame(tip_data)
df_tip_data.columns = ["Cust_id", "Rest_id", "Date", "Time", "Amount_no_tip", "Approved"]
df_tip_data["Amount_no_tip"] = df_tip_data["Amount_no_tip"].astype(int)

trans_count = df_trans_data.groupby(df_trans_data.Cust_id).count()["Rest_id"]
#amount_excluding_tip = df_tip_data.groupby(df_tip_data.Cust_id)["Amount_no_tip"].sum()
df1 = pd.merge(df_tz_data, df_trans_data, on = "Rest_id")

def change_time(date, time, gmt):
    type = time.split()[1]
    t = time.split()[0]
    hrs = t.split(":")[0]
    gmt_hrs = int(hrs) - int(gmt)
    d = date.split("-")[0]
    new_date = date
    if (gmt_hrs > 12):
        if type == "AM":
            type = "PM"
        else:
            new_date = str(int(d)+1) + "-" + date.split("-")[1] + "-" + date.split("-")[2]
            type = "AM" 
    
    if gmt_hrs < 0:
        if type == "AM":
            new_date = str(int(d)-1) + "-" + date.split("-")[1] + "-" + date.split("-")[2]
            type = "PM"
        else:
            type = "AM"
            
        new_t = str(12 + gmt_hrs) + ":" + t.split(":")[1] + ":" + t.split(":")[2] + " " + type
    
    new_t = str(gmt_hrs%12) + ":" + t.split(":")[1] + ":" + t.split(":")[2] + " " + type
    
    return [new_t,new_date]
    
new_time = []
new_date = []
for i in range(df1.shape[0]):
    new_time.append(change_time(df1.iloc[i,:].Date, df1.iloc[i,:].Time, df1.iloc[i,:].GMT_diff)[0])
    new_date.append(change_time(df1.iloc[i,:].Date, df1.iloc[i,:].Time, df1.iloc[i,:].GMT_diff)[1])

df1["Time"] = pd.Series(new_time)
df1["Date"] = pd.Series(new_date)

df2 = pd.merge(df1, df_tip_data, on = ["Rest_id","Time","Cust_id","Date"])

def find_tip_perc(amount, no_tip_amount):
    tip = amount - no_tip_amount
    tip_perc = float(tip)/float(no_tip_amount)
    return tip_perc
    
tip_perc = []
for i in range(df2.shape[0]):
    tip_perc.append(find_tip_perc(int(df2["Amount"].iloc[i]), int(df2["Amount_no_tip"].iloc[i])))

df2["Tip_perc"] = pd.Series(tip_perc)
amount_excluding_tip = df_tip_data.groupby(df_tip_data.Cust_id)["Amount_no_tip"].sum()
grouped_data =  df2.groupby(df2["Cust_id"])["Tip_perc"]
tip_perc = grouped_data.mean()

df_final = pd.DataFrame((tip_perc >= 0.2) & (trans_count >=2) & (amount_excluding_tip >=300))
df_final = df_final.reset_index()

for i in range(df_final.shape[0]):
    if int(df_final.iloc[i,1]) == 1 :
        text = "Y"
    else:
        text = "N"
        
    print df_final["Cust_id"].iloc[i] + "," + text 
