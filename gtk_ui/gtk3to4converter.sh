#!/bin/bash

sed -i 's|            <property name="primary-icon-activatable">False</property>||g' cityWeather.gtk3.glade
sed -i 's|            <property name="secondary-icon-activatable">False</property>||g' cityWeather.gtk3.glade
sed -i 's|            <property name="primary-icon-sensitive">False</property>||g' cityWeather.gtk3.glade
sed -i 's|            <property name="secondary-icon-sensitive">False</property>||g' cityWeather.gtk3.glade
sed -i 's|            <property name="shadow-type">none</property>||g' cityWeather.gtk3.glade

gtk4-builder-tool simplify --3to4 cityWeather.gtk3.glade > cityWeather.gtk4.glade
