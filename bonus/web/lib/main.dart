import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';
import 'package:web/firebase_options.dart';

void main() async {
  await Firebase.initializeApp(
    options: DefaultFirebaseOptions.currentPlatform,
  );

  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Bonus POO',
      theme: ThemeData(
        // This is the theme of your application.
        //
        // TRY THIS: Try running your application with "flutter run". You'll see
        // the application has a purple toolbar. Then, without quitting the app,
        // try changing the seedColor in the colorScheme below to Colors.green
        // and then invoke "hot reload" (save your changes or press the "hot
        // reload" button in a Flutter-supported IDE, or press "r" if you used
        // the command line to start the app).
        //
        // Notice that the counter didn't reset back to zero; the application
        // state is not lost during the reload. To reset the state, use hot
        // restart instead.
        //
        // This works for code too, not just values: Most code changes can be
        // tested with just a hot reload.
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      home: const BonusPoo(),
    );
  }
}

class BonusPoo extends StatefulWidget {
  const BonusPoo({super.key});

  @override
  State<BonusPoo> createState() => _BonusPooState();
}

class _BonusPooState extends State<BonusPoo> {
  bool isLoading = false;
  Map<String, dynamic>? data;
  bool hasError = false;
  final controller = TextEditingController();

  @override
  Widget build(BuildContext context) {
    var widgets = List<Widget>.empty(growable: true);
    var childern = [
      Container(
        constraints: const BoxConstraints(maxWidth: 320),
        child: TextFormField(
          decoration: const InputDecoration(label: Text("Numar Matricol")),
          controller: controller,
        ),
      ),
      const SizedBox(
        height: 8,
      ),
      if (hasError)
        const Text(
          "Some error occuured",
          style: TextStyle(color: Color.fromRGBO(255, 0, 0, 1.0)),
        ),
      if (isLoading)
        const SizedBox(
          width: 24,
          height: 24,
          child: CircularProgressIndicator(),
        )
      else if (data == null)
        TextButton(
            onPressed: () async {
              if (controller.text.isEmpty) {
                return;
              }
              if (controller.text.split("/").length != 2) {
                return;
              }
              var db = FirebaseFirestore.instance;
              final docRef = db
                  .collection("poo")
                  .doc(controller.text.trim().replaceAll("/", "_"));
              setState(() {
                isLoading = true;
              });
              try {
                var collection = await docRef.get();
                setState(() {
                  data = collection.data();
                });
              } finally {
                setState(() {
                  isLoading = false;
                });
              }
            },
            child: const Text("Search"))
    ];
    if (data != null) {
      var keys = data!.keys.toList()..sort();
      for (var key in keys) {
        widgets.add(Row(
          children: [
            const Spacer(),
            Text(key),
            const SizedBox(
              height: 8,
              width: 8,
            ),
            Text(data![key].toString()),
            const Spacer(),
          ],
        ));
        widgets.add(const SizedBox(
          height: 2,
        ));
      }

      childern.addAll(widgets);
    }

    return Scaffold(
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: childern,
        ),
      ),
    );
  }
}
