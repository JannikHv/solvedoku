const webpack = require('webpack');
const path = require('path');
let isDevelopment = true;
const config = {
  // entry: './src/index.ts',
  entry: [
    './src/solvedoku.ts'
  ],
  output: {
    path: path.resolve(__dirname, 'dist'),
    filename: 'bundle.js',
  },
  module: {
    rules: [
      {
        test: /\.tsx?$/,
        use: ['awesome-typescript-loader'],
        exclude: /node_modules/,
      },
      {
        test: /\.png$/,
        use: [
          {
            loader: 'url-loader',
            options: {
              mimetype: 'image/png',
            }
          }
        ]
      }
    ]
  },
  plugins: [],
  resolve: {
    extensions: ['.ts', '.tsx', '.js', 'scss'],
  },
  devServer: {
    writeToDisk: true,
    contentBase: path.join(__dirname, 'dist')
  }
};

module.exports = config;
