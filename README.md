Weather Rain Forecast 🌦️
Project Overview:-
The Weather Rain Forecast project is designed to predict rain and weather conditions using temperature and humidity data collected through DHT11 and DHT22 sensors. This project integrates Arduino for data collection and machine learning techniques for prediction, providing an efficient and interactive approach to weather monitoring.

Features:-
Real-time weather monitoring with DHT11 and DHT22 sensors.
Rain prediction using a trained machine learning model.
Arduino-based implementation for data collection.
Supports model training and testing through a Jupyter notebook.

Project Structure:-
weather_rain_forecast/
│── Train_the_model/
│   └── rain_dataset.xls  (Dataset for model training)
│   └── test_dataset.xls  (Dataset for testing the model)
│   └── weather_monitoring.ipynb (Jupyter notebook for model training and evaluation)
│── weather_rain_forecast_dht11/
│   └── weather_rain_forecast_dht11.ino (Arduino code for DHT11)
│── weather_rain_forecast_dht22/
│   └── weather_rain_forecast_dht22.ino (Arduino code for DHT22)
│── regression.h (Machine learning model - Linear Regression)
│── README.md

Necessary Libraries:-
DHT Sensor Library (Adafruit) v1.4.6 - Required for reading data from DHT11 and DHT22 sensors.
Python Libraries: Pandas, NumPy, Scikit-Learn, Matplotlib (for data analysis and visualization).

Usage:-
Use the Arduino setup to collect temperature and humidity data.
Run the machine learning model to predict rain probability.
Adjust and test the model using the Jupyter notebook.

Future Enhancements:-
Improve model accuracy with advanced algorithms.
Expand sensor compatibility (BMP180, BMP280).
Develop a web-based dashboard for remote monitoring.
Integrate mobile app notifications for real-time updates
